class Solution:
  def maxScore(self, nums: list[int], x: int) -> int:
    # Note that we always need to take nums[0], so the initial definition might
    # not hold true.

    # dp0 := the maximum score so far with `nums` ending in an even number
    dp0 = nums[0] - (x if nums[0] % 2 == 1 else 0)
    # dp0 := the maximum score so far with `nums` ending in an odd number
    dp1 = nums[0] - (x if nums[0] % 2 == 0 else 0)

    for i in range(1, len(nums)):
      if nums[i] % 2 == 0:
        dp0 = nums[i] + max(dp0, dp1 - x)
      else:
        dp1 = nums[i] + max(dp1, dp0 - x)

    return max(dp0, dp1)
