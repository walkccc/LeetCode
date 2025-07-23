class Solution:
  def subsequencePairCount(self, nums: list[int]) -> int:
    MOD = 1_000_000_007

    @functools.lru_cache(None)
    def dp(i: int, x: int, y: int) -> int:
      if i == len(nums):
        return int(x > 0 and x == y)
      # 1. Skip nums[i]
      skip = dp(i + 1, x, y)
      # 2. Pick nums[i] in the first subsequence
      take1 = dp(i + 1, math.gcd(x, nums[i]), y)
      # 3. Pick nums[i] in the second subsequence
      take2 = dp(i + 1, x, math.gcd(y, nums[i]))
      return (skip + take1 + take2) % MOD

    return dp(0, 0, 0)
