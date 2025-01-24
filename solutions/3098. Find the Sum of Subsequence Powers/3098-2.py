class Solution:
  def sumOfPowers(self, nums: list[int], k: int) -> int:
    kMod = 1_000_000_007
    n = len(nums)

    nums.sort()

    @functools.lru_cache(None)
    def dp(i: int, k: int, lastPickIndex: int, minDiff: int) -> int:
      if k == 0:
        return minDiff
      if i == n:
        return 0
      newMinDiff = (minDiff if lastPickIndex == - 1
                    else min(minDiff, nums[i] - nums[lastPickIndex]))
      pick = dp(i + 1, k - 1, i, newMinDiff)
      skip = dp(i + 1, k, lastPickIndex, minDiff)
      return (pick + skip) % kMod

    return dp(0, k, -1, math.inf)
