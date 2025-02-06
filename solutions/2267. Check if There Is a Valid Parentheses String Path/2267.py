class Solution:
  def hasValidPath(self, grid: list[list[str]]) -> bool:
    @functools.lru_cache(None)
    def dp(i: int, j: int, k: int) -> bool:
      """
      Returns True if there's a path from grid[i][j] to grid[m - 1][n - 1],
      where the number of '(' - the number of ')' == k.
      """
      if i == len(grid) or j == len(grid[0]):
        return False
      k += 1 if grid[i][j] == '(' else -1
      if k < 0:
        return False
      if i == len(grid) - 1 and j == len(grid[0]) - 1:
        return k == 0
      return dp(i + 1, j, k) | dp(i, j + 1, k)

    return dp(0, 0, 0)
