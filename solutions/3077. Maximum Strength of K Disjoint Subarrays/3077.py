class Solution:
  def maximumStrength(self, nums: list[int], k: int) -> int:

    @functools.lru_cache(None)
    def dp(i: int, k: int, fresh: bool) -> int:
      """
      Returns the maximum strength of nums[i..n) with k operations left, where
      `fresh` means we're starting a new subarray.
      """
      if len(nums) - i < k:
        return -math.inf
      if k == 0:
        return 0
      if i == len(nums):
        return 0 if k == 0 else -math.inf
      # If it's not fresh, we can't skip the current number and consider it as a
      # fresh start, since the case where it's fresh is already covered by
      # `includeAndFreshStart`.
      skip = dp(i + 1, k, True) if fresh else -math.inf
      gain = (-1 if k % 2 == 0 else 1) * nums[i] * k
      includeAndContinue = dp(i + 1, k, False) + gain
      includeAndFreshStart = dp(i + 1, k - 1, True) + gain
      return max(skip, includeAndContinue, includeAndFreshStart)

    return dp(0, k, True)
