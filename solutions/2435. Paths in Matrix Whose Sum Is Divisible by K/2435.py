class Solution:
  def numberOfPaths(self, grid: List[List[int]], k: int) -> int:
    kMod = 1_000_000_007
    m = len(grid)
    n = len(grid[0])

    @functools.lru_cache(None)
    def dp(i: int, j: int, summ: int) -> int:
      """
      Returns the number of paths to (i, j), where the sum / k == sum.
      """
      if i == m or j == n:
        return 0
      if i == m - 1 and j == n - 1:
        return 1 if (summ + grid[i][j]) % k == 0 else 0
      newSum = (summ + grid[i][j]) % k
      return (dp(i + 1, j, newSum) + dp(i, j + 1, newSum)) % kMod

    return dp(0, 0, 0)
