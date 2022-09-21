class Solution:
  def countPaths(self, grid: List[List[int]]) -> int:
    kMod = 1_000_000_007
    m = len(grid)
    n = len(grid[0])
    dirs = [0, 1, 0, -1, 0]

    # dp(i, j) := # of increasing paths starting from (i, j)
    @functools.lru_cache(None)
    def dp(i: int, j: int) -> int:
      ans = 1  # current cell contributes 1 length
      for k in range(4):
        x = i + dirs[k]
        y = j + dirs[k + 1]
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
