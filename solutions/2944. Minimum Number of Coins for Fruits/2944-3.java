class Solution {
  public int minimumCoins(int[] prices) {
    final int n = prices.length;
    int ans = Integer.MAX_VALUE;
    // Stores (dp[i], i), where dp[i] := the minimum number of coins to acquire
    // fruits[i:] (0-indexed) in ascending order.
    Deque<Pair<Integer, Integer>> minQ = new ArrayDeque<>();
    minQ.offerFirst(new Pair<>(0, n));

    for (int i = n - 1; i >= 0; --i) {
      while (!minQ.isEmpty() && minQ.peekFirst().getValue() > (i + 1) * 2)
        minQ.pollFirst();
      ans = prices[i] + minQ.peekFirst().getKey();
      while (!minQ.isEmpty() && minQ.peekLast().getKey() >= ans)
        minQ.pollLast();
      minQ.offerLast(new Pair<>(ans, i));
    }

    return ans;
  }
}
