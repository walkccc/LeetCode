class Solution {
  public int minDistance(String word1, String word2) {
    final int k = lcs(word1, word2);
    return (word1.length() - k) + (word2.length() - k);
  }

  private int lcs(final String a, final String b) {
    final int m = a.length();
    final int n = b.length();
    // dp[i][j] := the length of LCS(a[0..i), b[0..j))
    int[][] dp = new int[m + 1][n + 1];

    for (int i = 1; i <= m; ++i)
      for (int j = 1; j <= n; ++j)
        if (a.charAt(i - 1) == b.charAt(j - 1))
          dp[i][j] = 1 + dp[i - 1][j - 1];
        else
          dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);

    return dp[m][n];
  }
}
