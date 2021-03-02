class Solution:
  def knightDialer(self, N: int) -> int:
    kMod = int(1e9 + 7)
    dirs = [(1, 2), (2, 1), (2, -1), (1, -2),
            (-1, -2), (-2, -1), (-2, 1), (-1, 2)]

    # dp[i][j] := # of ways to stand on (i, j)
    dp = [[1] * 3 for _ in range(4)]
    dp[3][0] = dp[3][2] = 0

    for _ in range(N - 1):
      newDp = [[0] * 3 for _ in range(4)]
      for i in range(4):
        for j in range(3):
          if (i, j) == (3, 0) or (i, j) == (3, 2):
            continue
          for dx, dy in dirs:
            x = i + dx
            y = j + dy
            if 0 <= x < 4 and 0 <= y < 3 and \
                    (x, y) != (3, 0) and (x, y) != (3, 2):
              newDp[i][j] = (newDp[i][j] + dp[x][y]) % kMod
      dp = newDp

    return sum(map(sum, dp)) % kMod
