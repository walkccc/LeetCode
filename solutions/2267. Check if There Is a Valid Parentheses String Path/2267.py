class Solution:
  def hasValidPath(self, grid: List[List[chr]]) -> bool:
    # dp(i, j, k) := 1 if there's a path from grid[i][j] to grid[m - 1][n - 1]
    # w// # of '(' - # of ')' == k
    @functools.lru_cache(None)
    def dp(i: int, j: int, k: int) -> int:
      if i == len(grid) or j == len(grid[0]):
        return 0
      k += 1 if grid[i][j] == '(' else -1
      if k < 0:
        return 0
      if i == len(grid) - 1 and j == len(grid[0]) - 1:
        return k == 0
      return dp(i + 1, j, k) | dp(i, j + 1, k)

    return dp(0, 0, 0)
