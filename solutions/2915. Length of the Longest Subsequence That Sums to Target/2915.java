class Solution {
  public int lengthOfLongestSubsequence(List<Integer> nums, int target) {
    final int n = nums.size();
    // dp[i][j] := the maximum length of any subsequence of the first i numbers
    // that sum to j
    int[][] dp = new int[n + 1][target + 1];
    Arrays.stream(dp).forEach(A -> Arrays.fill(A, -1));

    for (int i = 0; i <= n; ++i)
      dp[i][0] = 0;

    for (int i = 1; i <= n; ++i) {
      final int num = nums.get(i - 1);
      for (int j = 1; j <= target; ++j) {
        // 1. Skip `num`.
        if (j < num || dp[i - 1][j - num] == -1)
          dp[i][j] = dp[i - 1][j];
        // 2. Skip `num` or pick `num`.
        else
          dp[i][j] = Math.max(dp[i - 1][j], 1 + dp[i - 1][j - num]);
      }
    }

    return dp[n][target];
  }
}
