class Solution {
  public int maxSum(int[] nums, int k, int m) {
    final int INF = 20_000_000;
    final int n = nums.length;
    int[] prefix = new int[n + 1];
    // dp[i][ongoing][r] := the maximum sum of nums[i..n - 1], with `ongoing`
    // indicating if a subarray is currently being extended (1) or not (0), and
    // `r` segments left to choose
    int[][][] dp = new int[n + 1][2][k + 1];

    for (int i = 0; i < n; ++i)
      prefix[i + 1] = prefix[i] + nums[i];

    Arrays.stream(dp).forEach(row -> Arrays.stream(row).forEach(col -> Arrays.fill(col, -INF)));

    // Base case: At the end of the array, if no segments are left, score is 0.
    dp[n][0][0] = dp[n][1][0] = 0;

    for (int i = n - 1; i >= 0; --i)
      for (int rem = 0; rem <= k; ++rem) {
        // When no subarray is ongoing:
        // 1. Skip nums[i].
        dp[i][0][rem] = dp[i + 1][0][rem];
        // 2. Start a new segment of length m (only if rem > 0 and there're
        // enough elements)
        if (rem > 0 && i + m <= n)
          dp[i][0][rem] =
              Math.max(dp[i][0][rem], dp[i + m][1][rem - 1] + (prefix[i + m] - prefix[i]));
        // When a subarray is ongoing:
        // 1. End the current subarray (transition to state 0, same index i)
        // 2. Extend the current subarray by picking nums[i] and move to i + 1
        dp[i][1][rem] = Math.max(dp[i][0][rem], dp[i + 1][1][rem] + nums[i]);
      }

    return dp[0][0][k];
  }
}
