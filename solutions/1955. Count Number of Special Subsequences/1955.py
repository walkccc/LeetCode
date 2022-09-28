class Solution:
  def countSpecialSubsequences(self, nums: List[int]) -> int:
    kMod = 1_000_000_007

    # dp(i, j) := # of special subseqs of nums[i:] and prev + 1 = j
    @functools.lru_cache(None)
    def dp(i: int, prev: int) -> int:
      if i == len(nums):
        return prev == 2

      ans = 0

      # not include nums[i]
      ans += dp(i + 1, prev)

      # include nums[i]
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
