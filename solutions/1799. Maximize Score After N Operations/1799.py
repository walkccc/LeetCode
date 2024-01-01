class Solution:
  def maxScore(self, nums: List[int]) -> int:
    n = len(nums) // 2

    @functools.lru_cache(None)
    def dp(op: int, mask: int) -> int:
      if op == n + 1:
        return 0

      res = 0

      for i in range(len(nums)):
        for j in range(i + 1, len(nums)):
          chosenMask = 1 << i | 1 << j
          if (mask & chosenMask) == 0:
            res = max(res,
                      op * math.gcd(nums[i], nums[j]) + dp(op + 1, mask | chosenMask))

      return res

    return dp(1, 0)
