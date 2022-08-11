class Solution:
  def knightProbability(self, N: int, K: int, r: int, c: int) -> float:
    dirs = [(1, 2), (2, 1), (2, -1), (1, -2),
            (-1, -2), (-2, -1), (-2, 1), (-1, 2)]

    # dp[i][j] := probability to stand on (i, j)
    dp = [[0] * N for _ in range(N)]
    dp[r][c] = 1

    for _ in range(K):
      newDp = [[0] * N for _ in range(N)]
      for i in range(N):
        for j in range(N):
          for dx, dy in dirs:
            x = i + dx
            y = j + dy
            if 0 <= x < N and 0 <= y < N:
              newDp[i][j] += dp[x][y]
      dp = newDp

    return sum(map(sum, dp)) / 8**K
