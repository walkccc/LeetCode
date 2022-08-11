class Solution {
  public int findMaxValueOfEquation(int[][] points, int k) {
    int ans = Integer.MIN_VALUE;
    Deque<Pair<Integer, Integer>> q = new ArrayDeque<>(); // (y - x, x) max queue

    for (int[] p : points) {
      final int x = p[0];
      final int y = p[1];
      // remove invalid points, xj - xi > k
      while (!q.isEmpty() && x - q.peekFirst().getValue() > k)
        q.pollFirst();
      if (!q.isEmpty())
        ans = Math.max(ans, x + y + q.peekFirst().getKey());
      // remove points that contribute less value and have bigger x
      while (!q.isEmpty() && y - x >= q.peekLast().getKey())
        q.pollLast();
      q.offerLast(new Pair<>(y - x, x));
    }

    return ans;
  }
}
