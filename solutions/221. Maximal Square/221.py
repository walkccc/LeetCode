class Solution:
  def maximalSquare(self, matrix: List[List[str]]) -> int:
    m = len(matrix)
    n = len(matrix[0])
    dp = [[0] * n for _ in range(m)]
    maxLength = 0

    for i in range(m):
      for j in range(n):
        if i == 0 or j == 0 or matrix[i][j] == '0':
          dp[i][j] = 1 if matrix[i][j] == '1' else 0
        else:
          dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1]
                         [j], dp[i][j - 1]) + 1
        maxLength = max(maxLength, dp[i][j])

    return maxLength * maxLength
