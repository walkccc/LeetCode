class Solution {
  public int splitArray(int[] nums, int k) {
    final int n = nums.length;
    // dp[i][k] := the minimum of the maximum sum to split the first i nums into
    // k groups
    dp = new int[n + 1][k + 1];
    prefix = new int[n + 1];

    Arrays.stream(dp).forEach(A -> Arrays.fill(A, Integer.MAX_VALUE));

    for (int i = 0; i < n; ++i)
      prefix[i + 1] = nums[i] + prefix[i];

    return splitArray(nums, n, k);
  }

  private int[][] dp;
  private int[] prefix;

  private int splitArray(int[] nums, int i, int k) {
    if (k == 1)
      return prefix[i];
    if (dp[i][k] < Integer.MAX_VALUE)
      return dp[i][k];

    // Try all the possible partitions.
    for (int j = k - 1; j < i; ++j)
      dp[i][k] = Math.min(dp[i][k], Math.max(splitArray(nums, j, k - 1), prefix[i] - prefix[j]));

    return dp[i][k];
  }
}
