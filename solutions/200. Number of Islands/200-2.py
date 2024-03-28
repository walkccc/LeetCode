class Solution:
  def numIslands(self, grid: List[List[str]]) -> int:
    m = len(grid)
    n = len(grid[0])

    def dfs(i: int, j: int) -> None:
      if i < 0 or i == m or j < 0 or j == n:
        return
      if grid[i][j] != '1':
        return

      grid[i][j] = '2'  # Mark '2' as visited.
      dfs(i + 1, j)
      dfs(i - 1, j)
      dfs(i, j + 1)
      dfs(i, j - 1)

    ans = 0

    for i in range(m):
      for j in range(n):
        if grid[i][j] == '1':
          dfs(i, j)
          ans += 1

    return ans
