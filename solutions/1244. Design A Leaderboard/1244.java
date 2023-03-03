class Leaderboard {
  public void addScore(int playerId, int score) {
    idToScore.put(playerId, idToScore.getOrDefault(playerId, 0) + score);
  }

  public int top(int K) {
    int ans = 0;
    Queue<Integer> minHeap = new PriorityQueue<>();

    for (final int score : idToScore.values()) {
      minHeap.offer(score);
      if (minHeap.size() > K)
        minHeap.poll();
    }

    while (!minHeap.isEmpty())
      ans += minHeap.poll();

    return ans;
  }

  public void reset(int playerId) {
    idToScore.remove(playerId);
  }

  private Map<Integer, Integer> idToScore = new HashMap<>();
}
