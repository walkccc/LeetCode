class Leaderboard {
  public void addScore(int playerId, int score) {
    idToScore.put(playerId, idToScore.getOrDefault(playerId, 0) + score);
  }

  public int top(int K) {
    int ans = 0;
    PriorityQueue<Integer> pq = new PriorityQueue<>();

    for (final int score : idToScore.values()) {
      pq.offer(score);
      if (pq.size() > K)
        pq.poll();
    }

    while (!pq.isEmpty())
      ans += pq.poll();

    return ans;
  }

  public void reset(int playerId) {
    idToScore.remove(playerId);
  }

  private Map<Integer, Integer> idToScore = new HashMap<>();
}
