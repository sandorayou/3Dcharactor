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
        }
        Console.WriteLine($"PASS: {checks} tracking assertions (production PoseInputMapper/PosePacket)");
    }
}
