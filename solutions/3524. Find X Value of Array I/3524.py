class Solution:
  def resultArray(self, nums: list[int], k: int) -> list[int]:
    ans = [0] * k
    # dp[r] := the number of subarrays ending at current position with
    # product % k == r
    dp = [0] * k

    for num in nums:
      newDp = [0] * k
      numMod = num % k
      # Start new subarray with only `num`
      newDp[numMod] = 1
      # Extend all previous subarrays
      for i in range(k):
        newMod = (i * numMod) % k
        newDp[newMod] += dp[i]
      # Accumulate counts into ans
      for i in range(k):
        ans[i] += newDp[i]
      dp = newDp

    return ans
