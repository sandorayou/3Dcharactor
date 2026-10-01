using System.IO;
using UnityEditor;
using UnityEditor.Build;
using UnityEditor.Build.Reporting;
using UnityEditor.UnityLinker;

namespace RealtimeBodyTracking.Editor
{
    public sealed class IOSPoseLinkerProcessor : IUnityLinkerProcessor
    {
        public int callbackOrder => 0;
        public string GenerateAdditionalLinkXmlFile(BuildReport report, UnityLinkerBuildPipelineData data)
        {
            if (data.target != BuildTarget.iOS) return null;
            var path = Path.GetFullPath("Temp/ios-pose-link.xml");
            Directory.CreateDirectory(Path.GetDirectoryName(path));
            // Native JSON packets are consumed by JsonUtility: retain their fields under High stripping.
            File.WriteAllText(path, "<linker><assembly fullname=\"Assembly-CSharp\">" +
                "<type fullname=\"RealtimeBodyTracking.PosePacket\" preserve=\"all\"/>" +
                "<type fullname=\"RealtimeBodyTracking.PosePoint\" preserve=\"all\"/>" +
                "<type fullname=\"RealtimeBodyTracking.PoseRotation\" preserve=\"all\"/>" +
                "<type fullname=\"RealtimeBodyTracking.FaceBlendshape\" preserve=\"all\"/>" +
                "</assembly></linker>");
            return path;
        }
    }
}
