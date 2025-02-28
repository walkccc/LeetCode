class Solution:
  def minimumWhiteTiles(
      self,
      floor: str,
      numCarpets: int,
      carpetLen: int,
  ) -> int:
    n = len(floor)
    # dp[i][j] := the minimum number of visible white tiles of floor[i..n)
    # after covering at most j carpets
    dp = [[0] * (numCarpets + 1) for _ in range(n + 1)]

    for i in reversed(range(n)):
      dp[i][0] = int(floor[i]) + dp[i + 1][0]

    for i in reversed(range(n)):
      for j in range(1, numCarpets + 1):
        cover = dp[i + carpetLen][j - 1] if i + carpetLen < n else 0
        skip = int(floor[i]) + dp[i + 1][j]
        dp[i][j] = min(cover, skip)

    return dp[0][numCarpets]
