class Solution:
  def numberOfPaths(self, grid: List[List[int]], k: int) -> int:
    kMod = 1_000_000_007
    m = len(grid)
    n = len(grid[0])
    # dp[i][j][sum] := the number of paths to (i, j), where the sum / k == sum
    dp = [[[0] * k for j in range(n)] for i in range(m)]
    dp[0][0][grid[0][0] % k] = 1

    for i in range(m):
      for j in range(n):
        for summ in range(k):
          newSum = (summ + grid[i][j]) % k
          if i > 0:
            dp[i][j][newSum] += dp[i - 1][j][summ]
          if j > 0:
            dp[i][j][newSum] += dp[i][j - 1][summ]
          dp[i][j][newSum] %= kMod

    return dp[m - 1][n - 1][0]
