class Solution:
  def findPoisonedDuration(self, timeSeries: list[int], duration: int) -> int:
    if duration == 0:
      return 0

    ans = 0

    for i in range(0, len(timeSeries) - 1):
      ans += min(timeSeries[i + 1] - timeSeries[i], duration)

    return ans + duration
