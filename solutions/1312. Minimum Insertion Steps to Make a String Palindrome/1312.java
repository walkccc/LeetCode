class Solution {
  public int minInsertions(String s) {
    return s.length() - longestPalindromeSubseq(s);
  }

  // same as 516. Longest Palindromic Subsequence
  public int longestPalindromeSubseq(String s) {
    final int n = s.length();
    // dp[i][j] := LPS's length in s[i..j]
    int[][] dp = new int[n][n];

    for (int i = 0; i < n; ++i)
      dp[i][i] = 1;

    for (int d = 1; d < n; ++d)
      for (int i = 0; i + d < n; ++i) {
        final int j = i + d;
        if (s.charAt(i) == s.charAt(j))
          dp[i][j] = 2 + dp[i + 1][j - 1];
        else
          dp[i][j] = Math.max(dp[i + 1][j], dp[i][j - 1]);
      }

    return dp[0][n - 1];
  }
}
