class Solution:
  def specialPerm(self, nums: list[int]) -> int:
    kMod = 1_000_000_007
    maxMask = 1 << len(nums)

    @functools.lru_cache(None)
    def dp(prev: int, mask: int) -> int:
      """
      Returns the number of special permutations, where the previous number is
      nums[i] and `mask` is the bitmask of the used numbers.
      """
      if mask == maxMask - 1:
        return 1

      res = 0

      for i, num in enumerate(nums):
        if mask >> i & 1:
          continue
        if num % nums[prev] == 0 or nums[prev] % num == 0:
          res += dp(i, mask | 1 << i)
          res %= kMod

      return res

    return sum(dp(i, 1 << i)
               for i in range(len(nums))) % kMod
