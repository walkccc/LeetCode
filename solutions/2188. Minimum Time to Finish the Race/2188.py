class Solution:
  def minimumFinishTime(self, tires: List[List[int]], changeTime: int, numLaps: int) -> int:
    # singleTire[i] := min time to finish i laps w//o changing tire
    singleTire = [math.inf] * (numLaps + 1)
    # dp[i] := min time to finish i laps
    dp = [math.inf] * (numLaps + 1)

    for i, (f, r) in enumerate(tires):
      sumSecs = 0
      rPower = 1
      for j in range(1, numLaps + 1):
        # time to use the same tire for next lap >=
        # time to change a new tire + f
        if f * rPower >= changeTime + f:
          break
        sumSecs += f * rPower
        rPower *= r
        singleTire[j] = min(singleTire[j], sumSecs)

    dp[0] = 0
    for i in range(1, numLaps + 1):
      for j in range(1, i + 1):
        dp[i] = min(dp[i], dp[i - j] + changeTime + singleTire[j])

    return dp[numLaps] - changeTime
