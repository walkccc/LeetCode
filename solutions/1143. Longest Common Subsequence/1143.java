class Solution {
  public int longestCommonSubsequence(String text1, String text2) {
    final int m = text1.length();
    final int n = text2.length();

    // dp[i][j] := LCS's length of text1[0..i) and text2[0..j)
    int[][] dp = new int[m + 1][n + 1];

    for (int i = 1; i <= m; ++i)
      for (int j = 1; j <= n; ++j)
        if (text1.charAt(i - 1) == text2.charAt(j - 1))
          dp[i][j] = 1 + dp[i - 1][j - 1];
        else
          dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);

    return dp[m][n];
  }
}
