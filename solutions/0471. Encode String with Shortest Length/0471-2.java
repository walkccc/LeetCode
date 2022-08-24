class Solution {
  public String encode(String s) {
    final int n = s.length();
    // dp[i][j] := shortest encoded String of s[i..j]
    String[][] dp = new String[n][n];

    for (int d = 0; d < n; ++d) {
      for (int i = 0; i + d < n; ++i) {
        final int j = i + d;
        final String curr = s.substring(i, j + 1);
        dp[i][j] = curr;

        if (dp[i][j].length() < 5)
          continue;

        // try all possible partitions
        for (int k = i; k < j; ++k)
          if (dp[i][k].length() + dp[k + 1][j].length() < dp[i][j].length())
            dp[i][j] = dp[i][k] + dp[k + 1][j];

        // try to compress theString
        // e.g. s = aabaabaab -> 3[aab]
        for (int k = i; k <= j; ++k) {
          final String pattern = s.substring(i, k + 1);
          if (curr.length() % pattern.length() == 0 && curr.replaceAll(pattern, "").isEmpty()) {
            final String candidate =
                String.valueOf(curr.length() / pattern.length()) + "[" + dp[i][k] + "]";
            if (candidate.length() < dp[i][j].length())
              dp[i][j] = candidate;
          }
        }
      }
    }

    return dp[0][n - 1];
  }
}
