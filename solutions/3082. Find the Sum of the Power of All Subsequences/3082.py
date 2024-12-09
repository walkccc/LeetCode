class Solution:
  def sumOfPower(self, nums: list[int], k: int) -> int:
    kMod = 1_000_000_007

    @functools.lru_cache(None)
    def dp(i: int, j: int) -> int:
      """Returns the number of subsequences in nums[i..n) that sums to j."""
      if j == 0:
        # For each of the remaining number, we can either pick it or skip it.
        return pow(2, len(nums) - i, kMod)
      if i == len(nums) or j < 0:
        return 0
        # 1. Include nums[i] in the subsequence and pick it.
        # 2. Include nums[i] in the subsequence and skip it.
        # 3. Exclude nums[i] in the subsequence.
      return (dp(i + 1, j - nums[i]) + 2 * dp(i + 1, j)) % kMod

    return dp(0, k)
