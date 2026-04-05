class Solution {
  // Similar to 516. Longest Palindromic Subsequence
  public int longestPalindromicSubsequence(String s, int k) {
    final int n = s.length();
    // dp[i][j][op] := the length of LPS(s[i..j]) with at most `op` operations
    int[][][] dp = new int[n][n][k + 1];

    for (int i = 0; i < n; ++i)
      for (int op = 0; op <= k; ++op)
        dp[i][i][op] = 1;

    for (int d = 1; d < n; ++d)
      for (int i = 0; i + d < n; ++i) {
        final int j = i + d;
        for (int op = 0; op <= k; ++op) {
          if (s.charAt(i) == s.charAt(j)) {
            dp[i][j][op] = 2 + dp[i + 1][j - 1][op];
          } else {
            dp[i][j][op] = Math.max(dp[i + 1][j][op], dp[i][j - 1][op]);
            final int cost = getCost(s.charAt(i), s.charAt(j));
            if (cost <= op)
              dp[i][j][op] = Math.max(dp[i][j][op], 2 + dp[i + 1][j - 1][op - cost]);
          }
        }
      }

    return dp[0][n - 1][k];
  }

  private int getCost(char a, char b) {
    final int dist = Math.abs(a - b);
    return Math.min(dist, 26 - dist);
  }
}
