class Solution:
  def maxScore(self, nums: list[int]) -> int:
    n = len(nums)
    # dp[i] := the maximum score to jump from index i to n - 1
    dp = [0] * n

    for i in reversed(range(n)):
      for j in range(i + 1, n):
        # Jump from i to j, and then jump from j to n - 1.
        dp[i] = max(dp[i], (j - i) * nums[j] + dp[j])

    return dp[0]
