class Solution:
  def removeOnes(self, grid: list[list[int]]) -> int:
    m = len(grid)
    n = len(grid[0])

    @functools.lru_cache(None)
    def dp(mask: int) -> int:
      """
      Returns the minimum number of operations to remove all 1s from the grid,
      where `mask` is the bitmask of the state of the grid.
      """
      if mask == 0:
        return 0
      ans = math.inf
      for i in range(m):
        for j in range(n):
          if mask >> i * n + j & 1:  # grid[i][j] == 1
            nextMask = mask
            for k in range(n):  # Set the cells in the same row with 0.
              nextMask &= ~(1 << i * n + k)
            for k in range(m):  # Set the cells in the same column with 0.
              nextMask &= ~(1 << k * n + j)
            ans = min(ans, 1 + dp(nextMask))
      return ans

    return dp(self.encode(grid, m, n))

  def encode(self, grid: list[list[int]], m: int, n: int) -> int:
    encoded = 0
    for i in range(m):
      for j in range(n):
        if grid[i][j]:
          encoded |= 1 << i * n + j
    return encoded
