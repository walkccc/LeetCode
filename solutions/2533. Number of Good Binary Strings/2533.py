class Solution:
  def goodBinaryStrings(
      self,
      minLength: int,
      maxLength: int,
      oneGroup: int,
      zeroGroup: int,
  ) -> int:
    kMod = 1_000_000_007
    # dp[i] := the number of good binary strings with length i
    dp = [1] + [0] * maxLength

    for i in range(maxLength + 1):
      # There are good binary strings with length i, so we can append
      # consecutive 0s or 1s after it.
      if dp[i] > 0:
        appendZeros = i + zeroGroup
        if appendZeros <= maxLength:
          dp[appendZeros] += dp[i]
          dp[appendZeros] %= kMod
        appendOnes = i + oneGroup
        if appendOnes <= maxLength:
          dp[appendOnes] += dp[i]
          dp[appendOnes] %= kMod

    return sum(dp[minLength:]) % kMod
