class Solution:
  def maxCoins(self, nums: list[int]) -> int:
    n = len(nums)
    # dp[i][j] := maxCoins(nums[i..j])
    dp = [[0] * (n + 2) for _ in range(n + 2)]

    nums = [1] + nums + [1]

    for d in range(n):
      for i in range(1, n - d + 1):
        j = i + d
        for k in range(i, j + 1):
          dp[i][j] = max(
              dp[i][j],
              dp[i][k - 1] +
              dp[k + 1][j] +
              nums[i - 1] * nums[k] * nums[j + 1])

    return dp[1][n]
