class Solution {
  // Same as 2944. Minimum Number of Coins for Fruits
  public int minimumCoins(int[] prices) {
    final int n = prices.length;
    int ans = 0;
    // Stores (dp[i], i), where dp[i] := the minimum number of coins to acquire
    // fruits[i:] (0-indexed).
    Queue<Pair<Integer, Integer>> minHeap = new PriorityQueue<>(Comparator.comparing(Pair::getKey));
    minHeap.offer(new Pair<>(0, n));

    for (int i = n - 1; i >= 0; --i) {
      while (!minHeap.isEmpty() && minHeap.peek().getValue() > (i + 1) * 2)
        minHeap.poll();
      ans = prices[i] + minHeap.peek().getKey();
      minHeap.offer(new Pair<>(ans, i));
    }

    return ans;
  }
}
