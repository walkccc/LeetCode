class Solution:
  def maxHammingDistances(self, nums: list[int], m: int) -> list[int]:
    kMaxMask = 1 << m
    # dp[i] := the maximum hamming distance from i to any number in `nums`
    dp = [-math.inf] * kMaxMask

    for num in nums:
      dp[num] = 0

    for bit in range(m):
      newDp = [0] * kMaxMask
      for mask in range(kMaxMask):
        newDp[mask] = max(dp[mask], dp[mask ^ (1 << bit)] + 1)
      dp = newDp

    return [dp[num] for num in nums]
