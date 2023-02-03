class Solution:
  def maxUncrossedLines(self, A: List[int], B: List[int]) -> int:
    m = len(A)
    n = len(B)
    dp = [[0] * (n + 1) for _ in range(m + 1)]

    for i in range(1, m + 1):
      for j in range(1, n + 1):
        dp[i][j] = dp[i - 1][j - 1] + 1 if A[i - 1] == B[j - 1] \
            else max(dp[i - 1][j], dp[i][j - 1])

    return dp[m][n]
