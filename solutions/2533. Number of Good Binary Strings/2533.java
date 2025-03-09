class Solution {
  public int goodBinaryStrings(int minLength, int maxLength, int oneGroup, int zeroGroup) {
    final int MOD = 1_000_000_007;
    // dp[i] := the number of good binary strings with length i
    int[] dp = new int[maxLength + 1];
    dp[0] = 1; // ""

    for (int i = 0; i <= maxLength; ++i)
      // There are good binary strings with length i, so we can append
      // consecutive 0s or 1s after it.
      if (dp[i] > 0) {
        final int appendZeros = i + zeroGroup;
        if (appendZeros <= maxLength) {
          dp[appendZeros] += dp[i];
          dp[appendZeros] %= MOD;
        }
        final int appendOnes = i + oneGroup;
        if (appendOnes <= maxLength) {
          dp[appendOnes] += dp[i];
          dp[appendOnes] %= MOD;
        }
      }

    int ans = 0;
    for (int i = minLength; i <= maxLength; ++i) {
      ans += dp[i];
      ans %= MOD;
    }
    return ans;
  }
}
