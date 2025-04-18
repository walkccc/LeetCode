class Solution {
  public long minimumCost(int[] nums, int[] cost, int k) {
    final int n = nums.length;
    long[] prefixNums = new long[n + 1];
    long[] prefixCost = new long[n + 1];
    // dp[i] := the minimum cost to divide nums[i..n - 1] into subarrays
    long[] dp = new long[n + 1];

    for (int i = 0; i < n; ++i) {
      prefixNums[i + 1] = prefixNums[i] + nums[i];
      prefixCost[i + 1] = prefixCost[i] + cost[i];
    }

    Arrays.fill(dp, Long.MAX_VALUE);
    dp[n] = 0;

    for (int i = n - 1; i >= 0; --i)
      for (int j = i; j < n; ++j)
        dp[i] = Math.min(dp[i], prefixNums[j + 1] * (prefixCost[j + 1] - prefixCost[i]) +
                                    k * (prefixCost[n] - prefixCost[i]) + dp[j + 1]);

    return dp[0];
  }
}
