class Solution:
  def knightProbability(self, n: int, k: int, row: int, column: int) -> float:
    dirs = ((1, 2), (2, 1), (2, -1), (1, -2),
            (-1, -2), (-2, -1), (-2, 1), (-1, 2))
    # dp[i][j] := the probability to stand on (i, j)
    dp = [[0] * n for _ in range(n)]
    dp[row][column] = 1.0

    for _ in range(k):
      newDp = [[0] * n for _ in range(n)]
      for i in range(n):
        for j in range(n):
          for dx, dy in dirs:
            x = i + dx
            y = j + dy
            if 0 <= x < n and 0 <= y < n:
              newDp[i][j] += dp[x][y]
      dp = newDp

    return sum(map(sum, dp)) / 8**k
