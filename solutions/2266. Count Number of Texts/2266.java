class Solution {
  public int countTexts(String pressedKeys) {
    final int kMod = 1_000_000_007;
    final int n = pressedKeys.length();
    // dp[i] := the number of possible text messages of pressedKeys[i..n)
    long[] dp = new long[n + 1];
    dp[n] = 1; // ""

    for (int i = n - 1; i >= 0; --i) {
      dp[i] = dp[i + 1];
      if (isSame(pressedKeys, i, 2))
        dp[i] += dp[i + 2];
      if (isSame(pressedKeys, i, 3))
        dp[i] += dp[i + 3];
      if ((pressedKeys.charAt(i) == '7' || pressedKeys.charAt(i) == '9') &&
          isSame(pressedKeys, i, 4))
        dp[i] += dp[i + 4];
      dp[i] %= kMod;
    }

    return (int) dp[0];
  }

  // Returns true if s[i..i + k) are the same digits.
  private boolean isSame(final String s, int i, int k) {
    if (i + k > s.length())
      return false;
    for (int j = i + 1; j < i + k; ++j)
      if (s.charAt(j) != s.charAt(i))
        return false;
    return true;
  }
}
