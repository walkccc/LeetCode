class Solution:
  def maxKilledEnemies(self, grid: list[list[str]]) -> int:
    m = len(grid)
    n = len(grid[0])
    enemyCount = 0
    # dp[i][j] := the maximum enemies grid[i][j] can kill
    dp = [[0] * n for _ in range(m)]

    def update(i: int, j: int) -> None:
      nonlocal enemyCount
      if grid[i][j] == '0':
        dp[i][j] += enemyCount
      elif grid[i][j] == 'E':
        enemyCount += 1
      else:  # grid[i][j] == 'W'
        enemyCount = 0

    # Extend the four directions, if meet 'W', need to start over from 0.
    for i in range(m):
      enemyCount = 0
      for j in range(n):
        update(i, j)
      enemyCount = 0
      for j in reversed(range(n)):
        update(i, j)

    for j in range(n):
      enemyCount = 0
      for i in range(m):
        update(i, j)
      enemyCount = 0
      for i in reversed(range(m)):
        update(i, j)

    # Returns sum(map(sum, dp))
    return max(map(max, dp))
