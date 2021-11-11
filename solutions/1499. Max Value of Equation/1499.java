class Solution {
  public int findMaxValueOfEquation(int[][] points, int k) {
    int ans = Integer.MIN_VALUE;
    // (y - x, x) max-heap
    PriorityQueue<Pair<Integer, Integer>> pq = new PriorityQueue<>(
        (a, b) -> a.getKey() == b.getKey() ? b.getValue() - a.getValue() : b.getKey() - a.getKey());

    for (int[] p : points) {
      final int x = p[0];
      final int y = p[1];
      while (!pq.isEmpty() && x - pq.peek().getValue() > k)
        pq.poll();
      if (!pq.isEmpty())
        ans = Math.max(ans, x + y + pq.peek().getKey());
      pq.offer(new Pair<>(y - x, x));
    }

    return ans;
  }
}
