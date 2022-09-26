class Solution {
  public int longestRepeatingSubstring(String S) {
    final int n = S.length();
    int ans = 0;
    // dp[i][j] := # of repeating chars of S[0..i) and S[0..j)
    int[][] dp = new int[n + 1][n + 1];

    for (int i = 1; i <= n; ++i)
      for (int j = i + 1; j <= n; ++j)
        if (S.charAt(i - 1) == S.charAt(j - 1)) {
          dp[i][j] = 1 + dp[i - 1][j - 1];
          ans = Math.max(ans, dp[i][j]);
        }

    return ans;
  }
}
