class VideoSharingPlatform {
  public int upload(String video) {
    final int videoId = getVideoId();
    videoIdToVideo.put(videoId, video);
    return videoId;
  }

  public void remove(int videoId) {
    if (videoIdToVideo.containsKey(videoId)) {
      usedIds.offer(videoId);
      videoIdToVideo.remove(videoId);
      videoIdToViews.remove(videoId);
      videoIdToLikes.remove(videoId);
      videoIdToDislikes.remove(videoId);
    }
  }

  public String watch(int videoId, int startMinute, int endMinute) {
    if (!videoIdToVideo.containsKey(videoId))
      return "-1";
    videoIdToViews.merge(videoId, 1, Integer::sum);
    final String video = videoIdToVideo.get(videoId);
    return video.substring(startMinute, Math.min(endMinute + 1, video.length()));
  }

  public void like(int videoId) {
    if (videoIdToVideo.containsKey(videoId))
      videoIdToLikes.merge(videoId, 1, Integer::sum);
  }

  public void dislike(int videoId) {
    if (videoIdToVideo.containsKey(videoId))
      videoIdToDislikes.merge(videoId, 1, Integer::sum);
  }

  public int[] getLikesAndDislikes(int videoId) {
    return videoIdToVideo.containsKey(videoId)
        ? new int[] {videoIdToLikes.getOrDefault(videoId, 0),
                     videoIdToDislikes.getOrDefault(videoId, 0)}
        : new int[] {-1};
  }

  public int getViews(int videoId) {
    return videoIdToVideo.containsKey(videoId) ? videoIdToViews.getOrDefault(videoId, 0) : -1;
  }

  private int currVideoId = 0;
  private Queue<Integer> usedIds = new PriorityQueue<>();
  private Map<Integer, String> videoIdToVideo = new HashMap<>();
  private Map<Integer, Integer> videoIdToViews = new HashMap<>();
  private Map<Integer, Integer> videoIdToLikes = new HashMap<>();
  private Map<Integer, Integer> videoIdToDislikes = new HashMap<>();

  private int getVideoId() {
    if (usedIds.isEmpty())
      return currVideoId++;
    return usedIds.poll();
  }
}
