class Solution:
  def minDays(self, grid: list[list[int]]) -> int:
    dirs = ((0, 1), (1, 0), (0, -1), (-1, 0))
    m = len(grid)
    n = len(grid[0])

    def dfs(grid: list[list[int]], i: int, j: int, seen: set[tuple[int, int]]):
      seen.add((i, j))
      for dx, dy in dirs:
        x = i + dx
        y = j + dy
        if x < 0 or x == m or y < 0 or y == n:
          continue
        if grid[x][y] == 0 or (x, y) in seen:
          continue
        dfs(grid, x, y, seen)

    def disconnected(grid: list[list[int]]) -> bool:
      islandsCount = 0
      seen = set()
      for i in range(m):
        for j in range(n):
          if grid[i][j] == 0 or (i, j) in seen:
            continue
          if islandsCount > 1:
            return True
          islandsCount += 1
          dfs(grid, i, j, seen)
      return islandsCount != 1

    if disconnected(grid):
      return 0

    # Try to remove 1 land.
    for i in range(m):
      for j in range(n):
        if grid[i][j] == 1:
          grid[i][j] = 0
          if disconnected(grid):
            return 1
          grid[i][j] = 1

    # Remove 2 lands.
    return 2
