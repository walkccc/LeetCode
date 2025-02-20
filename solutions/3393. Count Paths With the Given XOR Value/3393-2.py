class Solution:
  def countPathsWithXorValue(self, grid, k):
    kMod = 1_000_000_007
    kMax = 15
    m = len(grid)
    n = len(grid[0])
    # dp[i][j][xors] := the number of paths from (i, j) to (m - 1, n - 1) with
    # XOR value `xors`
    dp = [[[0] * (kMax + 1)
          for _ in range(n)]
          for _ in range(m)]

    dp[-1][-1][grid[-1][-1]] = 1

    for i in reversed(range(m)):
      for j in reversed(range(n)):
        for xors in range(kMax + 1):
          if i - 1 >= 0:
            newXor = xors ^ grid[i - 1][j]
            dp[i - 1][j][newXor] += dp[i][j][xors]
            dp[i - 1][j][newXor] %= kMod
          if j - 1 >= 0:
            newXor = xors ^ grid[i][j - 1]
            dp[i][j - 1][newXor] += dp[i][j][xors]
            dp[i][j - 1][newXor] %= kMod

    return dp[0][0][k]
