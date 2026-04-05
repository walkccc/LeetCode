class Solution {
  public String lexicographicallySmallestString(String s) {
    final int n = s.length();
    // dp[i][j]: the lexicographically smallest string by removing adjacent letters from s[i..j)
    String[][] dp = new String[n + 1][n + 1];

    // Initialize dp[i][i] = "" for all i.
    for (int i = 0; i <= n; ++i)
      dp[i][i] = "";

    for (int d = 1; d <= n; ++d)
      for (int i = 0; i + d <= n; ++i) {
        final int j = i + d;
        // 1. Keep s[i].
        String minString = s.charAt(i) + dp[i + 1][j];
        // 2. Remove s[i] and s[k] if possible.
        for (int k = i + 1; k < j; ++k)
          if (isConsecutive(s.charAt(i), s.charAt(k)) && dp[i + 1][k].isEmpty()) {
            final String candidate = dp[k + 1][j];
            if (candidate.compareTo(minString) < 0)
              minString = candidate;
          }
        dp[i][j] = minString;
      }

    return dp[0][n];
  }

  private boolean isConsecutive(char a, char b) {
    return Math.abs(a - b) == 1 || Math.abs(a - b) == 25;
  }
}
