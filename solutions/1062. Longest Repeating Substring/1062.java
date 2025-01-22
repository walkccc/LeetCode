class Solution {
  public int longestRepeatingSubstring(String s) {
    final int n = s.length();
    int ans = 0;
    // dp[i][j] := the number of repeating characters of s[0..i) and s[0..j)
    int[][] dp = new int[n + 1][n + 1];

    for (int i = 1; i <= n; ++i)
      for (int j = i + 1; j <= n; ++j)
        if (s.charAt(i - 1) == s.charAt(j - 1)) {
          dp[i][j] = 1 + dp[i - 1][j - 1];
          ans = Math.max(ans, dp[i][j]);
        }

    return ans;
  }
}
