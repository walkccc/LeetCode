class Solution:
  def maxSum(self, nums: list[int], k: int, m: int) -> int:
    INF = 20_000_000
    n = len(nums)
    prefix = list(itertools.accumulate(nums, initial=0))

    @functools.lru_cache(None)
    def dp(i: int, ongoing: int, k: int) -> int:
      if k < 0:
        return -INF
      if i == n:
        return 0 if k == 0 else -INF
      if ongoing == 1:
        # 1. End the current subarray (transition to state 0, same index i)
        # 2. Extend the current subarray by picking nums[i] and move to i + 1
        return max(dp(i, 0, k),
                   dp(i + 1, 1, k) + nums[i])
      # ongoing == 0
      # 1. Skip nums[i]
      # 2. Pick nums[i:i+m] (only if k > 0 and there're enough elements)
      res = dp(i + 1, 0, k)
      if i + m <= n:  # If we have enough elements for a new segment
        res = max(res,
                  dp(i + m, 1, k - 1) + (prefix[i + m] - prefix[i]))
      return res

    return dp(0, 0, k)
