class Solution:
  def minimumValueSum(self, nums: list[int], andValues: list[int]) -> int:
    n = len(nums)
    m = len(andValues)

    @functools.lru_cache(None)
    def dp(i: int, j: int, mask: int) -> int:
      """
      Returns the minimum value sum of nums[i..n) and andValues[j..m), where
      `mask` is the running value of the current subarray.
      """
      if i == n and j == m:
        return 0
      if i == n or j == m:
        return math.inf
      mask &= nums[i]
      if mask < andValues[j]:
        return math.inf
      if mask == andValues[j]:
        # 1. Keep going.
        # 2. End the subarray here and pick nums[i], then fresh start.
        return min(dp(i + 1, j, mask),
                   nums[i] + dp(i + 1, j + 1, -1))
      return dp(i + 1, j, mask)  # Keep going.

    ans = dp(0, 0, -1)
    return ans if ans < math.inf else -1
