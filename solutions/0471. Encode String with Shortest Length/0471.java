class Solution {
  public String encode(String s) {
    final int n = s.length();
    // dp[i][j] := shortest encoded String of s[i..j]
    dp = new String[n][n];
    return encode(s, 0, n - 1);
  }

  private String[][] dp;

  private String encode(final String s, int i, int j) {
    if (dp[i][j] != null)
      return dp[i][j];

    final String curr = s.substring(i, j + 1);
    dp[i][j] = curr;

    if (dp[i][j].length() < 5)
      return dp[i][j];

    // Try all the possible partitions.
    for (int k = i; k < j; ++k) {
      final String l = encode(s, i, k);
      final String r = encode(s, k + 1, j);
      if (l.length() + r.length() < dp[i][j].length())
        dp[i][j] = l + r;
    }

    // Try to compress the string.
    // e.g. s = aabaabaab -> 3[aab]
    for (int k = i; k <= j; ++k) {
      final String pattern = s.substring(i, k + 1);
      if (curr.length() % pattern.length() == 0 && curr.replaceAll(pattern, "").isEmpty()) {
        final String candidate =
            String.valueOf(curr.length() / pattern.length()) + "[" + encode(s, i, k) + "]";
        if (candidate.length() < dp[i][j].length())
          dp[i][j] = candidate;
      }
    }

    return dp[i][j];
  }
}
