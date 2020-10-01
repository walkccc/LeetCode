class Solution {
  public boolean isValidPalindrome(String s, int k) {
    return s.length() - longestPalindromeSubseq(s) <= k;
  }

  // same as 516. Longest Palindromic Subsequence
  private int longestPalindromeSubseq(final String s) {
    final int n = s.length();

    // dp[i][j] := LPS's length in s[i..j]
    int[][] dp = new int[n][n];

    for (int i = 0; i < n; ++i)
      dp[i][i] = 1;

    for (int length = 2; length <= n; ++length)
      for (int i = 0; i + length - 1 < n; ++i) {
        final int j = i + length - 1;
        if (s.charAt(i) == s.charAt(j))
          dp[i][j] = 2 + dp[i + 1][j - 1];
        else
          dp[i][j] = Math.max(dp[i + 1][j], dp[i][j - 1]);
      }

    return dp[0][n - 1];
  }
}