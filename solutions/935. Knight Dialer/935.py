class Solution:
  def knightDialer(self, n: int) -> int:
    dirs = ((1, 2), (2, 1), (2, -1), (1, -2),
            (-1, -2), (-2, -1), (-2, 1), (-1, 2))
    kMod = 1_000_000_007

    # dp[i][j] := the number of ways stand on (i, j)
    dp = [[1] * 3 for _ in range(4)]
    dp[3][0] = dp[3][2] = 0

    for _ in range(n - 1):
      newDp = [[0] * 3 for _ in range(4)]
      for i in range(4):
        for j in range(3):
          if (i, j) in ((3, 0), (3, 2)):
            continue
          for dx, dy in dirs:
            x = i + dx
            y = j + dy
            if x < 0 or x >= 4 or y < 0 or y >= 3:
              continue
            if (x, y) in ((3, 0), (3, 2)):
              continue
            newDp[x][y] = (newDp[x][y] + dp[i][j]) % kMod
      dp = newDp

    return sum(map(sum, dp)) % kMod
