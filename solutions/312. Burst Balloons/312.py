class Solution:
  def maxCoins(self, nums: list[int]) -> int:
    n = len(nums)
    nums = [1] + nums + [1]

    @functools.lru_cache(None)
    def dp(i: int, j: int) -> int:
      """Returns maxCoins(nums[i..j])."""
      if i > j:
        return 0
      return max(dp(i, k - 1) +
                 dp(k + 1, j) +
                 nums[i - 1] * nums[k] * nums[j + 1]
                 for k in range(i, j + 1))

    return dp(1, n)
