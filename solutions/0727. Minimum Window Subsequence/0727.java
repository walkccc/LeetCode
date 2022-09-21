class Solution {
  public String minWindow(String S, String T) {
    final int m = T.length();
    final int n = S.length();
    // dp[i][j] := start index (1-indexed) of
    // the minimum window of T[0..i] and S[0..j)
    int[][] dp = new int[m + 1][n + 1];

    // fill in placeholder values
    for (int j = 0; j <= n; ++j)
      dp[0][j] = j + 1;

    for (int i = 1; i <= m; ++i)
      for (int j = 1; j <= n; ++j)
        if (T.charAt(i - 1) == S.charAt(j - 1))
          dp[i][j] = dp[i - 1][j - 1];
        else
          dp[i][j] = dp[i][j - 1];

    int bestLeft = 0;
    int minLength = Integer.MAX_VALUE;

    for (int j = 1; j <= n; ++j)
      if (dp[m][j] > 0 && j - dp[m][j] + 1 < minLength) {
        bestLeft = dp[m][j] - 1;
        minLength = j - dp[m][j] + 1;
      }

    return minLength == Integer.MAX_VALUE ? "" : S.substring(bestLeft, bestLeft + minLength);
  }
}
