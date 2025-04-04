class Solution:
  def maxMoves(self, grid: list[list[int]]) -> int:
    m = len(grid)
    n = len(grid[0])
    # dp[i][j] := the maximum number of moves you can perform from (i, j)
    dp = [[0] * n for _ in range(m)]

    for j in range(n - 2, -1, -1):
      for i in range(m):
        if grid[i][j + 1] > grid[i][j]:
          dp[i][j] = 1 + dp[i][j + 1]
        if i > 0 and grid[i - 1][j + 1] > grid[i][j]:
          dp[i][j] = max(dp[i][j], 1 + dp[i - 1][j + 1])
        if i + 1 < m and grid[i + 1][j + 1] > grid[i][j]:
          dp[i][j] = max(dp[i][j], 1 + dp[i + 1][j + 1])

    return max(dp[i][0] for i in range(m))
