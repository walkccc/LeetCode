class Solution {
  public int longestPalindromeSubseq(String s) {
    final int n = s.length();
    // dp[i][j][k] := the length of LPS(s[i..j]) with the previous letter
    // (a' + k)
    dp = new int[n][n][27];
    return lps(s, 0, n - 1, 26);
  }

  private int[][][] dp;

  private int lps(final String s, int i, int j, int k) {
    if (i >= j)
      return 0;
    if (dp[i][j][k] > 0)
      return dp[i][j][k];

    if (s.charAt(i) == s.charAt(j) && s.charAt(i) != 'a' + k)
      dp[i][j][k] = lps(s, i + 1, j - 1, s.charAt(i) - 'a') + 2;
    else
      dp[i][j][k] = Math.max(lps(s, i + 1, j, k), lps(s, i, j - 1, k));

    return dp[i][j][k];
  }
}
