class VideoSharingPlatform {
 public:
  int upload(string video) {
    const int videoId = getVideoId();
    videoIdToVideo[videoId] = video;
    return videoId;
  }

  void remove(int videoId) {
    if (videoIdToVideo.count(videoId)) {
      usedIds.push(videoId);
      videoIdToVideo.erase(videoId);
      videoIdToViews.erase(videoId);
      videoIdToLikes.erase(videoId);
      videoIdToDislikes.erase(videoId);
    }
  }

  string watch(int videoId, int startMinute, int endMinute) {
    const auto it = videoIdToVideo.find(videoId);
    if (it == videoIdToVideo.cend())
      return "-1";
    ++videoIdToViews[videoId];
    const string video = it->second;
    const int duration =
        min(endMinute, static_cast<int>(video.length()) - 1) - startMinute + 1;
    return video.substr(startMinute, duration);
  }

  void like(int videoId) {
    if (videoIdToVideo.count(videoId))
      ++videoIdToLikes[videoId];
  }

  void dislike(int videoId) {
    if (videoIdToVideo.count(videoId))
      ++videoIdToDislikes[videoId];
  }

  vector<int> getLikesAndDislikes(int videoId) {
    return videoIdToVideo.count(videoId)
               ? vector<int>{videoIdToLikes[videoId],
                             videoIdToDislikes[videoId]}
               : vector<int>{-1};
  }

  int getViews(int videoId) {
    return videoIdToVideo.count(videoId) ? videoIdToViews[videoId] : -1;
  }

 private:
  int currVideoId = 0;
  priority_queue<int, vector<int>, greater<>> usedIds;
  unordered_map<int, string> videoIdToVideo;
  unordered_map<int, int> videoIdToViews;
  unordered_map<int, int> videoIdToLikes;
  unordered_map<int, int> videoIdToDislikes;

  int getVideoId() {
    if (usedIds.empty())
      return currVideoId++;
    const int minUsedId = usedIds.top();
    usedIds.pop();
    return minUsedId;
  }
};
