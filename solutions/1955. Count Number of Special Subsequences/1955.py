class Solution:
  def countSpecialSubsequences(self, nums: List[int]) -> int:
    kMod = 1_000_000_007

    @functools.lru_cache(None)
    def dp(i: int, prev: int) -> int:
      """
      Returns the number of increasing subsequences of the first i numbers,
      where the the previous number is j - 1.
      """
      if i == len(nums):
        return prev == 2

      ans = 0

      # Don't include the `nums[i]`.
      ans += dp(i + 1, prev)

      # Include the `nums[i]`.
      if nums[i] == prev:
        ans += dp(i + 1, prev)
      if prev == -1 and nums[i] == 0:
        ans += dp(i + 1, 0)
      if prev == 0 and nums[i] == 1:
        ans += dp(i + 1, 1)
      if prev == 1 and nums[i] == 2:
        ans += dp(i + 1, 2)

      ans %= kMod
      return ans

    return dp(0, -1)
