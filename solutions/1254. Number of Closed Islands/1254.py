class Solution:
  def closedIsland(self, grid: list[list[int]]) -> int:
    m = len(grid)
    n = len(grid[0])

    def dfs(i: int, j: int) -> None:
      if i < 0 or i == m or j < 0 or j == n:
        return
      if grid[i][j] == 1:
        return
      grid[i][j] = 1
      dfs(i + 1, j)
      dfs(i - 1, j)
      dfs(i, j + 1)
      dfs(i, j - 1)

    # Remove the lands connected to the edge.
    for i in range(m):
      for j in range(n):
        if i * j == 0 or i == m - 1 or j == n - 1:
          if grid[i][j] == 0:
            dfs(i, j)

    ans = 0

    # Reduce to 200. Number of Islands
    for i in range(m):
      for j in range(n):
        if grid[i][j] == 0:
          dfs(i, j)
          ans += 1

    return ans
