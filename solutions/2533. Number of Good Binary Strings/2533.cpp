class Solution {
 public:
  int goodBinaryStrings(int minLength, int maxLength, int oneGroup,
                        int zeroGroup) {
    constexpr int kMod = 1'000'000'007;
    // dp[i] := the number of good binary strings with length i
    vector<int> dp(maxLength + 1);
    dp[0] = 1;  // ""

    for (int i = 0; i <= maxLength; ++i)
      // There are good binary strings with length i, so we can append
      // consecutive 0s or 1s after it.
      if (dp[i] > 0) {
        const int appendZeros = i + zeroGroup;
        if (appendZeros <= maxLength) {
          dp[appendZeros] += dp[i];
          dp[appendZeros] %= kMod;
        }
        const int appendOnes = i + oneGroup;
        if (appendOnes <= maxLength) {
          dp[appendOnes] += dp[i];
          dp[appendOnes] %= kMod;
        }
      }

    return accumulate(dp.begin() + minLength, dp.end(), 0L) % kMod;
  }
};
