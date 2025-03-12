class Solution:
  def canPartition(self, nums: list[int]) -> bool:
    summ = sum(nums)
    if summ % 2 == 1:
      return False
    return self.knapsack_(nums, summ // 2)

  def knapsack_(self, nums: list[int], subsetSum: int) -> bool:
    n = len(nums)
    # dp[i][j] := True if j can be formed by nums[0..i)
    dp = [[False] * (subsetSum + 1) for _ in range(n + 1)]
    dp[0][0] = True

    for i in range(1, n + 1):
      num = nums[i - 1]
      for j in range(subsetSum + 1):
        if j < num:
          dp[i][j] = dp[i - 1][j]
        else:
          dp[i][j] = dp[i - 1][j] or dp[i - 1][j - num]

    return dp[n][subsetSum]
