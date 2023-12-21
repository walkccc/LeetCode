class TweetCounts {
  public void recordTweet(String tweetName, int time) {
    tweetNameToTimeCount.putIfAbsent(tweetName, new TreeMap<>());
    tweetNameToTimeCount.get(tweetName).merge(time, 1, Integer::sum);
  }

  public List<Integer> getTweetCountsPerFrequency(String freq, String tweetName, int startTime,
                                                  int endTime) {
    final int chunkSize = freq.equals("minute") ? 60 : freq.equals("hour") ? 3600 : 86400;
    int[] counts = new int[(endTime - startTime) / chunkSize + 1];
    TreeMap<Integer, Integer> timeCount = tweetNameToTimeCount.get(tweetName);

    for (Map.Entry<Integer, Integer> entry : timeCount.subMap(startTime, endTime + 1).entrySet()) {
      final int index = (entry.getKey() - startTime) / chunkSize;
      counts[index] += entry.getValue();
    }

    return Arrays.stream(counts).boxed().collect(Collectors.toList());
  }

  private Map<String, TreeMap<Integer, Integer>> tweetNameToTimeCount = new HashMap<>();
}
