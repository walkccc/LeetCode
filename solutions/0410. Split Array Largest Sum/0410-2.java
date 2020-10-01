class Solution {
  public int splitArray(int[] nums, int m) {
    final int n = nums.length;

    memo = new int[n + 1][m + 1];
    prefixSum = new int[n + 1];

    for (int[] row : memo)
      Arrays.fill(row, Integer.MAX_VALUE);

    for (int i = 1; i <= n; ++i)
      prefixSum[i] += prefixSum[i - 1] + nums[i - 1];

    return dp(nums, n, m);
  }

  private int[][] memo;
  private int[] prefixSum; // prefixSum[i] := sum of first i nums

  // dp(nums, n, m) := min of largest sum to split nums[0..n) into m groups
  private int dp(int[] nums, int n, int m) {
    if (m == 1)
      return prefixSum[n];
    int ans = memo[n][m];
    if (ans < Integer.MAX_VALUE)
      return ans;

    // try all possible partitions
    for (int i = m - 1; i < n; ++i)
      ans = Math.min(ans, Math.max(dp(nums, i, m - 1), prefixSum[n] - prefixSum[i]));

    return memo[n][m] = ans;
  }
}