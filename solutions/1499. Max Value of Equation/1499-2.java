class Solution {
  public int findMaxValueOfEquation(int[][] points, int k) {
    int ans = Integer.MIN_VALUE;
    Deque<Pair<Integer, Integer>> dq = new ArrayDeque<>(); // (y - x, x) max queue

    for (int[] p : points) {
      final int x = p[0];
      final int y = p[1];
      // Remove invalid points, xj - xi > k
      while (!dq.isEmpty() && x - dq.peekFirst().getValue() > k)
        dq.pollFirst();
      if (!dq.isEmpty())
        ans = Math.max(ans, x + y + dq.peekFirst().getKey());
      // Remove points that contribute less value and have bigger x
      while (!dq.isEmpty() && y - x >= dq.peekLast().getKey())
        dq.pollLast();
      dq.offerLast(new Pair<>(y - x, x));
    }

    return ans;
  }
}
