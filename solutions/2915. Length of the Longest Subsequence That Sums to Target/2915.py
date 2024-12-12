class Solution:
  def lengthOfLongestSubsequence(self, nums: list[int], target: int) -> int:
    n = len(nums)
    # dp[i][j] := the maximum length of any subsequence of the first i numbers
    # that sum to j
    dp = [[-1] * (target + 1) for _ in range(n + 1)]

    for i in range(n + 1):
      dp[i][0] = 0

    for i in range(1, n + 1):
      num = nums[i - 1]
      for j in range(1, target + 1):
        # 1. Skip `num`.
        if j < num or dp[i - 1][j - num] == -1:
          dp[i][j] = dp[i - 1][j]
        # 2. Skip `num` or pick `num`.
        else:
          dp[i][j] = max(dp[i - 1][j], 1 + dp[i - 1][j - num])

    return dp[n][target]
