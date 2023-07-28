class Solution {
  public int longestCommonSubsequence(String text1, String text2) {
    final int m = text1.length();
    final int n = text2.length();
    // dp[i][j] := LCS's length of text1[0..i) and text2[0..j)
    int[][] dp = new int[m + 1][n + 1];

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        dp[i + 1][j + 1] = text1.charAt(i) == text2.charAt(j)
                               ? 1 + dp[i][j]
                               : Math.max(dp[i][j + 1], dp[i + 1][j]);

    return dp[m][n];
  }
}
