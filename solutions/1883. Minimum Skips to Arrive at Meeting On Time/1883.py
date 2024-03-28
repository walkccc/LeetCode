class Solution:
  def minSkips(self, dist: List[int], speed: int, hoursBefore: int) -> int:
    kInf = 10**7
    kEps = 1e-9
    n = len(dist)
    # dp[i][j] := the minimum time, where i is the number of roads we traversed
    # so far and j is the number of skips we did
    dp = [[kInf] * (n + 1) for _ in range(n + 1)]
    dp[0][0] = 0

    for i, d in enumerate(dist, 1):
      dp[i][0] = math.ceil(dp[i - 1][0] + d / speed - kEps)
      for j in range(1, i + 1):
        dp[i][j] = min(dp[i - 1][j - 1] + d / speed,
                       math.ceil(dp[i - 1][j] + d / speed - kEps))

    for j, time in enumerate(dp[-1]):
      if time <= hoursBefore:
        return j

    return -1
