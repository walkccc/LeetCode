class Solution:
  def minCost(self, nums: list[int]) -> int:
    n = len(nums)

    @functools.lru_cache(None)
    def dp(last: int, i: int) -> int:
      if i == n:  # Single element left.
        return nums[last]
      if i == n - 1:  # Two elements left.
        return max(nums[last], nums[i])
      a = max(nums[i], nums[i + 1]) + dp(last, i + 2)
      b = max(nums[last], nums[i]) + dp(i + 1, i + 2)
      c = max(nums[last], nums[i + 1]) + dp(i, i + 2)
      return min(a, b, c)

    return dp(0, 1)
