class Solution:
  def angleClock(self, hour: int, minutes: int) -> float:
    hourAngle = (hour % 12) * 30 + minutes * 0.5
    minuteAngle = minutes * 6
    ans = abs(hourAngle - minuteAngle)

    return min(ans, 360 - ans)
