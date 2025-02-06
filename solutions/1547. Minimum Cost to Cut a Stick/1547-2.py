class Solution:
  def minCost(self, n: int, cuts: list[int]) -> int:
    arr = sorted([0] + cuts + [n])

    dp = [[0] * len(arr) for _ in range(len(arr))]

    for d in range(2, len(arr)):
      for i in range(len(arr) - d):
        j = i + d
        dp[i][j] = math.inf
        for k in range(i + 1, j):
          dp[i][j] = min(dp[i][j], arr[j] - arr[i] + dp[i][k] + dp[k][j])

    return dp[0][len(arr) - 1]
