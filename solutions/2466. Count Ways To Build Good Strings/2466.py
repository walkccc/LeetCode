class Solution:
  def countGoodStrings(self, low: int, high: int, zero: int, one: int) -> int:
    kMod = 1_000_000_007
    ans = 0
    # dp[i] := the number of good strings with length i
    dp = [1] + [0] * high

    for i in range(1, high + 1):
      if i >= zero:
        dp[i] = (dp[i] + dp[i - zero]) % kMod
      if i >= one:
        dp[i] = (dp[i] + dp[i - one]) % kMod
      if i >= low:
        ans = (ans + dp[i]) % kMod

    return ans
