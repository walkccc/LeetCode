class Solution:
  def countPathsWithXorValue(self, grid, k):
    kMod = 1_000_000_007
    kMax = 15
    m = len(grid)
    n = len(grid[0])
    # dp[i][j][xors] := the number of paths from (0, 0) to (i, j) with XOR
    # value `xors`
    dp = [[[0] * (kMax + 1)
          for _ in range(n)]
          for _ in range(m)]

    dp[0][0][grid[0][0]] = 1

    for i in range(m):
      for j in range(n):
        for xors in range(kMax + 1):
          if i + 1 < m:
            newXor = xors ^ grid[i + 1][j]
            dp[i + 1][j][newXor] += dp[i][j][xors]
            dp[i + 1][j][newXor] %= kMod
          if j + 1 < n:
            newXor = xors ^ grid[i][j + 1]
            dp[i][j + 1][newXor] += dp[i][j][xors]
            dp[i][j + 1][newXor] %= kMod

    return dp[-1][-1][k]
