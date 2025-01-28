class Solution:
  def minCostToEqualizeArray(
      self,
      nums: list[int],
      cost1: int,
      cost2: int,
  ) -> int:
    kMod = 1_000_000_007
    n = len(nums)
    minNum = min(nums)
    maxNum = max(nums)
    summ = sum(nums)

    if cost1 * 2 <= cost2 or n < 3:
      totalGap = maxNum * n - summ
      return (cost1 * totalGap) % kMod

    def getMinCost(target: int) -> int:
      """Returns the minimum cost to make all numbers equal to `target`."""
      maxGap = target - minNum
      totalGap = target * n - summ
      # Pair one shallowest number with one non-shallowest number, so the worst
      # case is that we have `totalGap - maxGap` non-shallowest numbers to pair.
      pairs = min(totalGap // 2, totalGap - maxGap)
      return cost1 * (totalGap - 2 * pairs) + cost2 * pairs

    return min(getMinCost(target)
               for target in range(maxNum, 2 * maxNum)) % kMod
