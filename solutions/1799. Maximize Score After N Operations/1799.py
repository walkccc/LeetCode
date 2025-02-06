class Solution:
  def maxScore(self, nums: list[int]) -> int:
    n = len(nums) // 2

    @functools.lru_cache(None)
    def dp(k: int, mask: int) -> int:
      """
      Returns the maximum score you can receive after performing the k to n
      operations, where `mask` is the bitmask of the chosen numbers.
      """
      if k == n + 1:
        return 0

      res = 0

      for i in range(len(nums)):
        for j in range(i + 1, len(nums)):
          chosenMask = 1 << i | 1 << j
          if (mask & chosenMask) == 0:
            res = max(
                res, k * math.gcd(nums[i], nums[j]) + dp(k + 1, mask | chosenMask))

      return res

    return dp(1, 0)
