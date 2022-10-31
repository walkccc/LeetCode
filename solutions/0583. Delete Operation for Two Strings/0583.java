class Solution {
  public int minDistance(String word1, String word2) {
    final int k = lcs(word1, word2);
    return (word1.length() - k) + (word2.length() - k);
  }

  private int lcs(final String A, final String B) {
    final int m = A.length();
    final int n = B.length();
    // dp[i][j] := LCS's length of A[0..i) and B[0..j)
    int[][] dp = new int[m + 1][n + 1];

    for (int i = 1; i <= m; ++i)
      for (int j = 1; j <= n; ++j)
        if (A.charAt(i - 1) == B.charAt(j - 1))
          dp[i][j] = 1 + dp[i - 1][j - 1];
        else
          dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);

    return dp[m][n];
  }
}
