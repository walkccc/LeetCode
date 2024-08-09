class Solution:
  def minPathCost(self, grid: List[List[int]], moveCost: List[List[int]]) -> int:
    m = len(grid)
    n = len(grid[0])
    # dp[i][j] := the minimum cost to reach grid[i][j]
    dp = [[math.inf] * n for _ in range(m)]
    dp[0] = grid[0]

    for i in range(1, m):
      for j in range(n):
        for k in range(n):
          dp[i][j] = min(dp[i][j], dp[i - 1][k] +
                         moveCost[grid[i - 1][k]][j] + grid[i][j])

    return min(dp[-1])
