class Solution {
  public int findMaxValueOfEquation(int[][] points, int k) {
    int ans = Integer.MIN_VALUE;
    Deque<Pair<Integer, Integer>> maxQ = new ArrayDeque<>(); // (y - x, x)

    for (int[] point : points) {
      final int x = point[0];
      final int y = point[1];
      // Remove the invalid points, xj - xi > k
      while (!maxQ.isEmpty() && x - maxQ.peekFirst().getValue() > k)
        maxQ.pollFirst();
      if (!maxQ.isEmpty())
        ans = Math.max(ans, x + y + maxQ.peekFirst().getKey());
      // Remove the points that contribute less value and have a bigger x.
      while (!maxQ.isEmpty() && y - x >= maxQ.peekLast().getKey())
        maxQ.pollLast();
      maxQ.offerLast(new Pair<>(y - x, x));
    }

    return ans;
  }
}
