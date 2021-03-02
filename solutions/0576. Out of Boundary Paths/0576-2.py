class Solution:
  def findPaths(self, m: int, n: int, N: int, i: int, j: int) -> int:
    dirs = [1, 0, -1, 0, 1]
    ans = 0
    dp = [[0] * n for _ in range(m)]
    dp[i][j] = 1

    for _ in range(N):
      newDp = [[0] * n for _ in range(m)]
      for r in range(m):
        for c in range(n):
          if dp[r][c] > 0:
            for dx, dy in zip(dirs, dirs[1:]):
              x = r + dx
              y = c + dy
              if 0 <= x < m and 0 <= y < n:
                newDp[x][y] += dp[r][c]
              else:
                ans += dp[r][c]
      dp = newDp

    return ans % int(1e9 + 7)
