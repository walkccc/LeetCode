class Solution {
  public int countPalindromes(String s) {
    final int MOD = 1_000_000_007;
    final int PATTERN_SIZE = 5;
    long ans = 0;

    for (char a = '0'; a <= '9'; ++a)
      for (char b = '0'; b <= '9'; ++b) {
        char[] pattern = {a, b, '.', b, a};
        // dp[i] := the number of subsequences of pattern[i..n) in s, where
        // pattern[2] can be any character
        long[] dp = new long[PATTERN_SIZE + 1];
        dp[PATTERN_SIZE] = 1;
        for (final char c : s.toCharArray())
          for (int i = 0; i < PATTERN_SIZE; ++i)
            if (pattern[i] == '.' || pattern[i] == c)
              dp[i] += dp[i + 1];
        ans += dp[0];
        ans %= MOD;
      }

    return (int) ans;
  }
}
