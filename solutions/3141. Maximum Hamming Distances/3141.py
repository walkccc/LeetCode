class Solution:
  def maxHammingDistances(self, nums: list[int], m: int) -> list[int]:
    MAX_MASK = 1 << m
    # dp[i] := the maximum hamming distance from i to any number in `nums`
    dp = [-math.inf] * MAX_MASK

    for num in nums:
      dp[num] = 0

    for bit in range(m):
      newDp = [0] * MAX_MASK
      for mask in range(MAX_MASK):
        newDp[mask] = max(dp[mask], dp[mask ^ (1 << bit)] + 1)
      dp = newDp

    return [dp[num] for num in nums]
