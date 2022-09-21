class VideoSharingPlatform:
  def __init__(self):
    self.currVideoId = 0
    self.usedIds = []
    self.videoIdToVideo = {}
    self.videoIdToViews = Counter()
    self.videoIdToLikes = Counter()
    self.videoIdToDislikes = Counter()

  def upload(self, video: str) -> int:
    videoId = self._getVideoId()
    self.videoIdToVideo[videoId] = video
    return videoId

  def remove(self, videoId: int) -> None:
    if videoId in self.videoIdToVideo:
      heapq.heappush(self.usedIds, videoId)
      del self.videoIdToVideo[videoId]
      del self.videoIdToViews[videoId]
      del self.videoIdToLikes[videoId]
      del self.videoIdToDislikes[videoId]

  def watch(self, videoId: int, startMinute: int, endMinute: int) -> str:
    if videoId not in self.videoIdToVideo:
      return '-1'
    self.videoIdToViews[videoId] += 1
    video = self.videoIdToVideo[videoId]
    return video[startMinute:min(endMinute + 1, len(video))]

  def like(self, videoId: int) -> None:
    if videoId in self.videoIdToVideo:
      self.videoIdToLikes[videoId] += 1

  def dislike(self, videoId: int) -> None:
    if videoId in self.videoIdToVideo:
      self.videoIdToDislikes[videoId] += 1

  def getLikesAndDislikes(self, videoId: int) -> List[int]:
    if videoId in self.videoIdToVideo:
      return [self.videoIdToLikes[videoId], self.videoIdToDislikes[videoId]]
    return [-1]

  def getViews(self, videoId: int) -> int:
    if videoId in self.videoIdToVideo:
      return self.videoIdToViews[videoId]
    return -1

  def _getVideoId(self) -> int:
    if not self.usedIds:
      self.currVideoId += 1
      return self.currVideoId - 1
    return heapq.heappop(self.usedIds)
