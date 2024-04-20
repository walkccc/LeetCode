class Solution {
  public int numDecodings(String s) {
    final int kMod = 1_000_000_007;
    final int n = s.length();
    // dp[i] := the number of ways to decode s[i..n - 1]
    long[] dp = new long[n + 1];
    dp[n] = 1;
    dp[n - 1] = count(s.charAt(n - 1));

    for (int i = n - 2; i >= 0; --i) {
      dp[i] += count(s.charAt(i), s.charAt(i + 1)) * dp[i + 2];
      dp[i] += count(s.charAt(i)) * dp[i + 1];
      dp[i] %= kMod;
    }

    return (int) dp[0];
  }

  private int count(char c) {
    if (c == '*')
      return 9;
    return c == '0' ? 0 : 1;
  }

  private int count(char c1, char c2) {
    if (c1 == '*' && c2 == '*')
      return 15; // c1c2: [11-19, 21-26]
    if (c1 == '*') {
      if ('0' <= c2 && c2 <= '6')
        return 2; // c1: [1-2]
      else
        return 1; // c1: [1]
    }
    if (c2 == '*') {
      if (c1 == '1')
        return 9; // c2: [1-9]
      if (c1 == '2')
        return 6; // c2: [1-6]
      return 0;
    }
    return (c1 == '1' || (c1 == '2' && c2 <= '6')) ? 1 : 0;
  }
}
