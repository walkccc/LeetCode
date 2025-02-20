class Solution:
  def countPaths(self, grid: list[list[int]]) -> int:
    kMod = 1_000_000_007
    dirs = ((0, 1), (1, 0), (0, -1), (-1, 0))
    m = len(grid)
    n = len(grid[0])

    @functools.lru_cache(None)
    def dp(i: int, j: int) -> int:
      """Returns the number of increasing paths starting from (i, j)."""
      ans = 1  # The current cell contributes 1 length.
      for dx, dy in dirs:
        x = i + dx
        y = j + dy
        if x < 0 or x == m or y < 0 or y == n:
          continue
        if grid[x][y] <= grid[i][j]:
          continue
        ans += dp(x, y)
        ans %= kMod
      return ans

    return sum(dp(i, j)
               for i in range(m)
               for j in range(n)) % kMod
