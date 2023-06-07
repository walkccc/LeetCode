class Solution {
  public int longestPalindrome(String word1, String word2) {
    final String s = word1 + word2;
    final int n = s.length();
    int ans = 0;
    // dp[i][j] := LPS's length in s[i..j]
    int[][] dp = new int[n][n];

    for (int i = 0; i < n; ++i)
      dp[i][i] = 1;

    for (int d = 1; d < n; ++d)
      for (int i = 0; i + d < n; ++i) {
        final int j = i + d;
        if (s.charAt(i) == s.charAt(j)) {
          dp[i][j] = 2 + dp[i + 1][j - 1];
          if (i < word1.length() && j >= word1.length())
            ans = Math.max(ans, dp[i][j]);
        } else {
          dp[i][j] = Math.max(dp[i + 1][j], dp[i][j - 1]);
        }
      }

    return ans;
  }
}
