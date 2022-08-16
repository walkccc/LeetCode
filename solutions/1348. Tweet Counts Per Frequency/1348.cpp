class TweetCounts {
 public:
  void recordTweet(string tweetName, int time) {
    ++tweetNameToTimeCount[tweetName][time];
  }

  vector<int> getTweetCountsPerFrequency(string freq, string tweetName,
                                         int startTime, int endTime) {
    const int chunkSize = freq == "minute" ? 60 : freq == "hour" ? 3600 : 86400;
    vector<int> counts((endTime - startTime) / chunkSize + 1);
    const auto& timeCount = tweetNameToTimeCount[tweetName];
    const auto lo = timeCount.lower_bound(startTime);
    const auto hi = timeCount.upper_bound(endTime);

    for (auto it = lo; it != hi; ++it) {
      const int index = (it->first - startTime) / chunkSize;
      counts[index] += it->second;
    }

    return counts;
  }

 private:
  unordered_map<string, map<int, int>> tweetNameToTimeCount;
};
