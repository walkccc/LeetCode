class Solution {
  public int[] maximumSubarrayXor(int[] nums, int[][] queries) {
    final int n = nums.length;
    int[] ans = new int[queries.length];
    // xors[i][j] := the XOR score of nums[i..j]
    int[][] xors = new int[n][n];
    // dp[i][j] := the maximum XOR score of nums[i..j]
    int[][] dp = new int[n][n];

    for (int i = 0; i < n; ++i) {
      xors[i][i] = nums[i];
      dp[i][i] = nums[i];
    }

    for (int d = 1; d < n; ++d)
      for (int i = 0; i + d < n; ++i) {
        final int j = i + d;
        xors[i][j] = xors[i][j - 1] ^ xors[i + 1][j];
        dp[i][j] = Math.max(xors[i][j], Math.max(dp[i][j - 1], dp[i + 1][j]));
      }

    for (int i = 0; i < queries.length; ++i) {
      final int l = queries[i][0];
      final int r = queries[i][1];
      ans[i] = dp[l][r];
    }

    return ans;
  }
}
