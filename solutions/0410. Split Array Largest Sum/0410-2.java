class Solution {
  public int splitArray(int[] nums, int k) {
    final int n = nums.length;
    // dp[i][k] := the minimum of the maximum sum to split the first i nums into
    // k groups
    int[][] dp = new int[n + 1][k + 1];
    Arrays.stream(dp).forEach(A -> Arrays.fill(A, Integer.MAX_VALUE));
    int[] prefix = new int[n + 1];

    for (int i = 1; i <= n; ++i) {
      prefix[i] = prefix[i - 1] + nums[i - 1];
      dp[i][1] = prefix[i];
    }

    for (int l = 2; l <= k; ++l)
      for (int i = l; i <= n; ++i)
        for (int j = l - 1; j < i; ++j)
          dp[i][l] = Math.min(dp[i][l], Math.max(dp[j][l - 1], prefix[i] - prefix[j]));

    return dp[n][k];
  }
}
