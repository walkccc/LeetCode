class Solution:
  def sumOfPower(self, nums: list[int], k: int) -> int:
    kMod = 1_000_000_007
    # dp[i] := the number of subsequences in nums so far that sums to k
    dp = [1] + [0] * k

    for num in nums:
      for i in range(k, -1, -1):
        if i < num:
          dp[i] = (dp[i] * 2) % kMod
        else:
          dp[i] = (dp[i] * 2 + dp[i - num]) % kMod

    return dp[k]
