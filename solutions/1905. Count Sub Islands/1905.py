class Solution:
  def countSubIslands(
      self,
      grid1: list[list[int]],
      grid2: list[list[int]],
  ) -> int:
    m = len(grid2)
    n = len(grid2[0])

    def dfs(i: int, j: int) -> int:
      if i < 0 or i == m or j < 0 or j == n:
        return 1
      if grid2[i][j] != 1:
        return 1

      grid2[i][j] = 2  # Mark 2 as visited.

      return (dfs(i + 1, j) & dfs(i - 1, j) &
              dfs(i, j + 1) & dfs(i, j - 1) & grid1[i][j])

    ans = 0

    for i in range(m):
      for j in range(n):
        if grid2[i][j] == 1:
          ans += dfs(i, j)

    return ans
