class Solution:
  def minimumOperations(self, grid: list[list[int]]) -> int:
    dirs = ((0, 1), (1, 0), (0, -1), (-1, 0))
    m = len(grid)
    n = len(grid[0])
    seen = [[0] * n for _ in range(m)]
    match = [[-1] * n for _ in range(m)]

    def dfs(i: int, j: int, sessionId: int) -> int:
      for dx, dy in dirs:
        x = i + dx
        y = j + dy
        if x < 0 or x == m or y < 0 or y == n:
          continue
        if grid[x][y] == 0 or seen[x][y] == sessionId:
          continue
        seen[x][y] = sessionId
        if match[x][y] == -1 or dfs(*divmod(match[x][y], n), sessionId):
          match[x][y] = i * n + j
          match[i][j] = x * n + y
          return 1
      return 0

    ans = 0

    for i in range(m):
      for j in range(n):
        if grid[i][j] == 1 and match[i][j] == -1:
          sessionId = i * n + j
          seen[i][j] = sessionId
          ans += dfs(i, j, sessionId)

    return ans
