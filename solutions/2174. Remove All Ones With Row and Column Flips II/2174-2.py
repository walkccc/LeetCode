class Solution:
  def removeOnes(self, grid: List[List[int]]) -> int:
    m = len(grid)
    n = len(grid[0])
    maxMask = 1 << m * n
    # dp[i] := the minimum number of operations to remove all 1s from the grid,
    # where bitmask i represents the state of the grid
    dp = [math.inf] * maxMask
    dp[0] = 0

    for mask in range(maxMask):
      for i in range(m):
        for j in range(n):
          if grid[i][j]:
            nextMask = mask
            for k in range(n):  # Set the cells in the same row with 0.
              nextMask &= ~(1 << i * n + k)
            for k in range(m):  # Set the cells in the same column with 0.
              nextMask &= ~(1 << k * n + j)
            dp[mask] = min(dp[mask], 1 + dp[nextMask])

    return dp[self.encode(grid, m, n)]

  def encode(self, grid: List[List[int]], m: int, n: int) -> int:
    encoded = 0
    for i in range(m):
      for j in range(n):
        if grid[i][j]:
          encoded |= 1 << i * n + j
    return encoded
