class Solution:
  def countSpecialSubsequences(self, nums: list[int]) -> int:
    kMod = 1_000_000_007

    @functools.lru_cache(None)
    def dp(i: int, prev: int) -> int:
      """
      Returns the number of increasing subsequences of the first i numbers,
      where the the previous number is j - 1.
      """
      if i == len(nums):
        return prev == 2

      res = 0

      # Don't include `nums[i]`.
      res += dp(i + 1, prev)

      # Include `nums[i]`.
      if nums[i] == prev:
        res += dp(i + 1, prev)
      if prev == -1 and nums[i] == 0:
        res += dp(i + 1, 0)
      if prev == 0 and nums[i] == 1:
        res += dp(i + 1, 1)
      if prev == 1 and nums[i] == 2:
        res += dp(i + 1, 2)

      res %= kMod
      return res

    return dp(0, -1)
