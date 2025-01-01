class Solution:
  def countRoutes(
      self,
      locations: list[int],
      start: int,
      finish: int,
      fuel: int,
  ) -> int:
    kMod = 1_000_000_007
    n = len(locations)
    # dp[i][j] := the number of ways to reach the `finish` city from the i-th
    # city with `j` fuel
    dp = [[0] * (fuel + 1) for _ in range(n)]

    for f in range(fuel + 1):
      dp[finish][f] = 1

    for f in range(fuel + 1):
      for i in range(n):
        for j in range(n):
          if i == j:
            continue
          requiredFuel = abs(locations[i] - locations[j])
          if requiredFuel <= f:
            dp[i][f] += dp[j][f - requiredFuel]
            dp[i][f] %= kMod

    return dp[start][fuel]
