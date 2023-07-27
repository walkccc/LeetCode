class Solution:
  def maximumScore(self, nums: List[int], multipliers: List[int]) -> int:
    @functools.lru_cache(2000)
    def dp(s: int, i: int) -> int:
      if i == len(multipliers):
        return 0

      e = len(nums) - (i - s) - 1
      pickStart = nums[s] * multipliers[i] + dp(s + 1, i + 1)
      pickEnd = nums[e] * multipliers[i] + dp(s, i + 1)
      return max(pickStart, pickEnd)

    return dp(0, 0)
