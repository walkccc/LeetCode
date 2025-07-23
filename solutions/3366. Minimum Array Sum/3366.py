class Solution:
  def minArraySum(self, nums: list[int], k: int, op1: int, op2: int) -> int:
    @functools.lru_cache(None)
    def dp(i: int, op1: int, op2: int) -> int:
      """
      Returns the minimum sum of nums[i..n - 1] with `op1` operations of op1 and
      `op2` operations of op2.
      """
      if i == len(nums):
        return 0
      res = nums[i] + dp(i + 1, op1, op2)
      if op1 > 0:
        res = min(res, (nums[i] + 1) // 2 + dp(i + 1, op1 - 1, op2))
      if op2 > 0 and nums[i] >= k:
        res = min(res, nums[i] - k + dp(i + 1, op1, op2 - 1))
      if op1 > 0 and op2 > 0:
        if (nums[i] + 1) // 2 >= k:
          res = min(res, (nums[i] + 1) // 2 - k + dp(i + 1, op1 - 1, op2 - 1))
        if nums[i] >= k:
          res = min(res, (nums[i] - k + 1) // 2 + dp(i + 1, op1 - 1, op2 - 1))
      return res

    return dp(0, op1, op2)
