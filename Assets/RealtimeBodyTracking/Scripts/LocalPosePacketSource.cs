namespace RealtimeBodyTracking
{
    public interface LocalPosePacketSource
    {
        bool TryTakeLatest(out PosePacket packet);
    }
}
