class Solution:
  def removeOnes(self, grid: list[list[int]]) -> int:
    m = len(grid)
    n = len(grid[0])
    maxMask = 1 << m * n
    # dp[i] := the minimum number of operations to remove all 1s from the grid,
    # where `i` is the bitmask of the state of the grid
    dp = [math.inf] * maxMask
    dp[0] = 0

    for mask in range(maxMask):
      for i in range(m):
        for j in range(n):
          if grid[i][j] == 1:
            nextMask = mask
            # Set the cells in the same row with 0.
            for k in range(n):
              nextMask &= ~(1 << i * n + k)
            # Set the cells in the same column with 0.
            for k in range(m):
              nextMask &= ~(1 << k * n + j)
            dp[mask] = min(dp[mask], 1 + dp[nextMask])

    return dp[self.encode(grid, m, n)]

  def encode(self, grid: list[list[int]], m: int, n: int) -> int:
    encoded = 0
    for i in range(m):
      for j in range(n):
        if grid[i][j]:
          encoded |= 1 << i * n + j
    return encoded
