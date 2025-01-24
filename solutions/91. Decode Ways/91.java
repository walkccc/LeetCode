class Solution {
  public int numDecodings(String s) {
    final int n = s.length();
    // dp[i] := the number of ways to decode s[i..n)
    int[] dp = new int[n + 1];
    dp[n] = 1; // ""
    dp[n - 1] = isValid(s.charAt(n - 1)) ? 1 : 0;

    for (int i = n - 2; i >= 0; --i) {
      if (isValid(s.charAt(i)))
        dp[i] += dp[i + 1];
      if (isValid(s.charAt(i), s.charAt(i + 1)))
        dp[i] += dp[i + 2];
    }

    return dp[0];
  }

  private boolean isValid(char c) {
    return c != '0';
  }

  private boolean isValid(char c1, char c2) {
    return c1 == '1' || c1 == '2' && c2 < '7';
  }
}
