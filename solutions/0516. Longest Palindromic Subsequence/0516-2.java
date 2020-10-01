class Solution {
  public int longestPalindromeSubseq(String s) {
    final int n = s.length();

    memo = new int[n][n];

    return dp(s, 0, n - 1);
  }

  private int[][] memo;

  // dp(s, i, j) := LPS's length in s[i..j]
  private int dp(final String s, int i, int j) {
    if (i > j)
      return 0;
    if (i == j)
      return 1;
    if (memo[i][j] > 0)
      return memo[i][j];
    if (s.charAt(i) == s.charAt(j))
      return memo[i][j] = 2 + dp(s, i + 1, j - 1);

    return memo[i][j] = Math.max(dp(s, i + 1, j), dp(s, i, j - 1));
  }
}