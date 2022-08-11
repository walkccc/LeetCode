class Solution {
  public int minimumDeleteSum(String s1, String s2) {
    final int m = s1.length();
    final int n = s2.length();
    // dp[i][j] := min cost to make s1[0..i) and s2[0..j) equal
    int[][] dp = new int[m + 1][n + 1];

    // delete s1.charAt(i - 1)
    for (int i = 1; i <= m; ++i)
      dp[i][0] = dp[i - 1][0] + s1.charAt(i - 1);

    // delete s2.charAt(j - 1)
    for (int j = 1; j <= n; ++j)
      dp[0][j] = dp[0][j - 1] + s2.charAt(j - 1);

    for (int i = 1; i <= m; ++i)
      for (int j = 1; j <= n; ++j)
        if (s1.charAt(i - 1) == s2.charAt(j - 1))
          dp[i][j] = dp[i - 1][j - 1];
        else
          dp[i][j] = Math.min(dp[i - 1][j] + s1.charAt(i - 1), dp[i][j - 1] + s2.charAt(j - 1));

    return dp[m][n];
  }
}
