class Solution:
  def isThereAPath(self, grid: List[List[int]]) -> bool:
    m = len(grid)
    n = len(grid[0])
    if m + n - 1 & 1:
      return False

    @functools.lru_cache(None)
    def dp(i: int, j: int, summ: int) -> bool:
      """
      Returns 1 if there's a path to grid[i][j] s.t.
      summ = (the number of 0s - the number of 1s).
      """
      if i == m or j == n:
        return False
      summ += 1 if grid[i][j] == 0 else -1
      if i == m - 1 and j == n - 1:
        return summ == 0
      return dp(i + 1, j, summ) or dp(i, j + 1, summ)

    return dp(0, 0, 0)
