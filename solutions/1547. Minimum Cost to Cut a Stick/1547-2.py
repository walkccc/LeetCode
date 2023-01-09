class Solution:
  def minCost(self, n: int, cuts: List[int]) -> int:
    A = sorted([0] + cuts + [n])

    dp = [[0] * len(A) for _ in range(len(A))]

    for d in range(2, len(A)):
      for i in range(len(A) - d):
        j = i + d
        dp[i][j] = math.inf
        for k in range(i + 1, j):
          dp[i][j] = min(dp[i][j], A[j] - A[i] + dp[i][k] + dp[k][j])

    return dp[0][len(A) - 1]
