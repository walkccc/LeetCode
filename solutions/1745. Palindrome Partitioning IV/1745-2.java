class Solution {
  public boolean checkPartitioning(String s) {
    final int n = s.length();
    // dp[i][j] := true if s[i..j] is a palindrome
    boolean[][] dp = new boolean[n][n];

    for (int i = 0; i < n; ++i)
      dp[i][i] = true;

    for (int d = 1; d < n; ++d)
      for (int i = 0; i + d < n; ++i) {
        final int j = i + d;
        if (s.charAt(i) == s.charAt(j))
          dp[i][j] = i + 1 > j - 1 || dp[i + 1][j - 1];
      }

    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j)
        if (dp[0][i] && dp[i + 1][j] && dp[j + 1][n - 1])
          return true;

    return false;
  }
}
