class Solution:
  def minimumIncrements(self, nums: list[int], target: list[int]) -> int:
    maxMask = 1 << len(target)
    maskToLcm = {}

    for mask in range(1, maxMask):
      subset = [num for i, num in enumerate(target) if mask >> i & 1]
      maskToLcm[mask] = functools.reduce(math.lcm, subset, 1)

    # dp[mask] := the minimum number of increments to make each number in the
    # subset of target have at least one number that is a multiple in `num`,
    # where `mask` is the bitmask of the subset of target
    dp = [math.inf] * maxMask
    dp[0] = 0

    for num in nums:
      # maskToCost := (mask, cost), where `mask` is the bitmask of the subset
      # of target and `cost` is the minimum number of increments to make each
      # number in the subset of target have at least one number that is a
      # multiple in `num`
      maskToCost = [
          (mask, 0 if (remainder := num % lcm) == 0 else lcm - remainder) for mask,
          lcm in maskToLcm.items()]
      newDp = dp[:]
      for prevMask in range(maxMask):
        if dp[prevMask] == float('inf'):
          continue
        for mask, cost in maskToCost:
          nextMask = prevMask | mask
          newDp[nextMask] = min(newDp[nextMask], dp[prevMask] + cost)
      dp = newDp

    return -1 if dp[-1] == math.inf else dp[-1]
