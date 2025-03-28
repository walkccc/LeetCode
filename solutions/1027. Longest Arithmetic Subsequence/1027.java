class Solution {
  public int longestArithSeqLength(int[] nums) {
    final int n = nums.length;
    int ans = 0;
    // dp[i][k] := the length of the longest arithmetic subsequence of nums[0..i]
    // with k = diff + 500
    int[][] dp = new int[n][1001];

    for (int i = 0; i < n; ++i)
      for (int j = 0; j < i; ++j) {
        final int k = nums[i] - nums[j] + 500;
        dp[i][k] = Math.max(2, dp[j][k] + 1);
        ans = Math.max(ans, dp[i][k]);
      }

    return ans;
  }
}
