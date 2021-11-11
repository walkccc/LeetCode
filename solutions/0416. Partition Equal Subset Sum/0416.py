class Solution:
  def canPartition(self, nums: List[int]) -> bool:
    summ = sum(nums)

    if summ & 1:
      return False

    dp = [True] + [False] * (summ // 2)

    for num in nums:
      for w in range(summ // 2, num - 1, -1):
        dp[w] = dp[w] or dp[w - num]

    return dp[summ // 2]
