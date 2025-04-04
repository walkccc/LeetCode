class Solution:
  def minArraySum(self, nums: list[int], k: int, op1: int, op2: int) -> int:
    n = len(nums)
    # dp[i][j][k] := the minimum sum of nums[i..n - 1] with j operations of op1
    # and k operations of op2
    dp = [[[math.inf] * (op2 + 1)
          for _ in range(op1 + 1)]
          for _ in range(n + 1)]

    # Base case: When index reaches the end of the array, the result is 0.
    for i in range(op1 + 1):
      for j in range(op2 + 1):
        dp[n][i][j] = 0

    for i in range(n - 1, -1, -1):
      for o1 in range(op1 + 1):
        for o2 in range(op2 + 1):
          summ = nums[i] + dp[i + 1][o1][o2]
          if o1 > 0:
            summ = min(summ, (nums[i] + 1) // 2 + dp[i + 1][o1 - 1][o2])
          if o2 > 0 and nums[i] >= k:
            summ = min(summ, nums[i] - k + dp[i + 1][o1][o2 - 1])
          if o1 > 0 and o2 > 0:
            if (nums[i] + 1) // 2 >= k:
              summ = min(summ,
                         (nums[i] + 1) // 2 - k + dp[i + 1][o1 - 1][o2 - 1])
            if nums[i] >= k:
              summ = min(summ,
                         (nums[i] - k + 1) // 2 + dp[i + 1][o1 - 1][o2 - 1])
          dp[i][o1][o2] = summ

    return dp[0][op1][op2]
