class Solution:
  def maximumScore(self, nums: list[int], multipliers: list[int]) -> int:
    @functools.lru_cache(2000)
    def dp(s: int, i: int) -> int:
      """Returns the maximum score of nums[s..e] and multipliers[i]."""
      if i == len(multipliers):
        return 0

      # The number of nums picked on the start side is s.
      # The number of nums picked on the end side is i - s.
      # So, e = n - (i - s) - 1.
      e = len(nums) - (i - s) - 1
      pickStart = nums[s] * multipliers[i] + dp(s + 1, i + 1)
      pickEnd = nums[e] * multipliers[i] + dp(s, i + 1)
      return max(pickStart, pickEnd)

    return dp(0, 0)
