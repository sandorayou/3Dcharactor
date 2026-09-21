using System;
using System.Collections.Generic;
using UnityEngine;
using RealtimeBodyTracking;

static class Program
{
    static int checks;
    static void Check(bool condition, string name) { if (!condition) throw new Exception(name); checks++; }
    static bool Near(float a, float b) => Math.Abs(a-b) < .0001f;
    static PosePoint Point(string name, float x, float y, float confidence=1) => new PosePoint
        { name=name, image_x=x, image_y=y, x=x, y=y, confidence=confidence };
    static void Main()
    {
        foreach (bool mirror in new[] { false, true })
        foreach (float noise in new[] { -.001f, 0f, .001f })
        {
            var packet = new PosePacket { version=2, points=new List<PosePoint> {
                Point("left_eye", .6f, .3f), Point("right_eye", .4f, .3f+noise) } };
            Check(PoseInputMapper.TryReadHeadRoll(packet, mirror, .5f, out var roll), "roll tracked");
            Check(Math.Abs(roll) < 1f, "level eyes must not produce 180 degree roll");
        }
        var weak = new PosePacket { version=2, points=new List<PosePoint> {
            Point("left_shoulder", .7f,.4f, .01f), Point("right_shoulder",.3f,.4f) } };
        Check(!PoseInputMapper.TryReadUpperBody(weak,false,.85f,out _), "weak shoulder rejected");
        weak.points[0].confidence=1;
        Check(PoseInputMapper.TryReadUpperBody(weak,false,.85f,out _), "strong shoulders accepted without hips");
        weak.points.Clear();
        Check(!PoseInputMapper.TryReadUpperBody(weak,false,.85f,out _), "lost shoulders rejected");
        Check(!PoseInputMapper.TryReadHeadRoll(weak,false,.5f,out _), "lost eyes rejected");
        foreach (bool mirror in new[] { false, true })
        {
            var p=PoseInputMapper.ImageToViewport(new Vector2(.25f,.25f),640,480,4f/3f,mirror);
            Check(Near(p.x,mirror?.75f:.25f)&&Near(p.y,.75f),"front/rear same aspect");
            p=PoseInputMapper.ImageToViewport(new Vector2(.4f,.25f),640,480,9f/16f,mirror);
            Check(Near(p.x,.5f+(mirror?.1f:-.1f)*(4f/3f)/(9f/16f))&&Near(p.y,.75f),"portrait horizontal crop");
            p=PoseInputMapper.ImageToViewport(new Vector2(.25f,.4f),640,480,16f/9f,mirror);
            Check(Near(p.x,mirror?.75f:.25f)&&Near(p.y,.5f+.1f*(16f/9f)/(4f/3f)),"landscape vertical crop");
            var leftShoulder = PoseInputMapper.ImageToViewport(new Vector2(.4f,.4f),640,480,9f/16f,mirror);
            var rightShoulder = PoseInputMapper.ImageToViewport(new Vector2(.6f,.4f),640,480,9f/16f,mirror);
            Check(Near(Vector2.Distance(leftShoulder,rightShoulder), .2f*(4f/3f)/(9f/16f)), "portrait shoulder width uses visible crop");
        }

        foreach (bool mirror in new[] { false, true })
        {
            var pose = new PosePacket { version=4, source_width=640, source_height=480,
                points=new List<PosePoint> {
                    Point("left_shoulder", .35f, .40f), Point("right_shoulder", .65f, .46f) } };
            Check(PoseInputMapper.TryReadPreviewShoulders(
                pose, 9f/16f, mirror, .6f, out var sourceLeft, out var sourceRight),
                "preview shoulders available");
            var expectedLeft = PoseInputMapper.ImageToViewport(
                new Vector2(.35f,.40f),640,480,9f/16f,mirror);
            var expectedRight = PoseInputMapper.ImageToViewport(
                new Vector2(.65f,.46f),640,480,9f/16f,mirror);
            Check(Vector2.Distance(sourceLeft, expectedLeft) < .0001f &&
                  Vector2.Distance(sourceRight, expectedRight) < .0001f,
                  "shoulders use displayed preview transform");

            var avatarLeft = new Vector2(.18f,.57f);
            var avatarRight = new Vector2(.82f,.43f);
            const float currentDepth = 2f;
            Check(PoseInputMapper.TrySolveScreenAlignment(
                sourceLeft, sourceRight, avatarLeft, avatarRight,
                currentDepth, .25f, 8f, out var alignment),
                "screen alignment solved");
            var projectionScale = currentDepth / alignment.TargetDepth;
            var alignedLeft = alignment.SourceCenter +
                              (avatarLeft - alignment.AvatarCenter) * projectionScale;
            var alignedRight = alignment.SourceCenter +
                               (avatarRight - alignment.AvatarCenter) * projectionScale;
            Check(Vector2.Distance((alignedLeft+alignedRight)*.5f, alignment.SourceCenter) < .0001f,
                "aligned shoulder center is exact");
            Check(Near(Vector2.Distance(alignedLeft,alignedRight), alignment.SourceWidth),
                "aligned shoulder scale is exact");
        }

        var rearA = new PosePacket { version=4, source_width=640, source_height=480,
            points=new List<PosePoint> { Point("left_shoulder",.25f,.4f), Point("right_shoulder",.55f,.4f) } };
        var rearB = new PosePacket { version=4, source_width=640, source_height=480,
            points=new List<PosePoint> { Point("left_shoulder",.35f,.4f), Point("right_shoulder",.65f,.4f) } };
        PoseInputMapper.TryReadPreviewShoulders(rearA,4f/3f,false,.6f,out var rearAL,out var rearAR);
        PoseInputMapper.TryReadPreviewShoulders(rearB,4f/3f,false,.6f,out var rearBL,out var rearBR);
        PoseInputMapper.TryReadPreviewShoulders(rearA,4f/3f,true,.6f,out var frontAL,out var frontAR);
        PoseInputMapper.TryReadPreviewShoulders(rearB,4f/3f,true,.6f,out var frontBL,out var frontBR);
        Check((rearBL.x+rearBR.x) > (rearAL.x+rearAR.x), "rear preview follows raw lateral direction");
        Check((frontBL.x+frontBR.x) < (frontAL.x+frontAR.x), "front preview follows displayed mirrored direction");
        Check(PoseInputMapper.SourceIsLeftForAvatarSide(true, false) &&
              !PoseInputMapper.SourceIsLeftForAvatarSide(false, false),
              "rear preview preserves anatomical limb assignment");
        Check(!PoseInputMapper.SourceIsLeftForAvatarSide(true, true) &&
              PoseInputMapper.SourceIsLeftForAvatarSide(false, true),
              "front preview swaps anatomical limb assignment");

        rearA.points[0].confidence=.1f;
        Check(!PoseInputMapper.TryReadPreviewShoulders(rearA,4f/3f,false,.6f,out _,out _),
            "low confidence disables screen alignment");
        rearA.points.Clear();
        Check(!PoseInputMapper.TryReadPreviewShoulders(rearA,4f/3f,false,.6f,out _,out _),
            "tracking loss disables screen alignment");
        Check(!PoseInputMapper.TrySolveScreenAlignment(
            Vector2.zero,Vector2.zero,new Vector2(.2f,.4f),new Vector2(.8f,.4f),2f,.25f,8f,out _),
            "zero source span disables screen alignment");
        Console.WriteLine($"PASS: {checks} tracking assertions (production PoseInputMapper/PosePacket)");
    }
}
