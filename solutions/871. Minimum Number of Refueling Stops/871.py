class Solution:
  def minRefuelStops(
      self,
      target: int,
      startFuel: int,
      stations: list[list[int]],
  ) -> int:
    # dp[i] := the farthest position we can reach w / i refuels
    dp = [startFuel] + [0] * len(stations)

    for i, station in enumerate(stations):
      for j in range(i + 1, 0, -1):
        if dp[j - 1] >= station[0]:
          dp[j] = max(dp[j], dp[j - 1] + station[1])

    for i, d in enumerate(dp):
      if d >= target:
        return i

    return -1
