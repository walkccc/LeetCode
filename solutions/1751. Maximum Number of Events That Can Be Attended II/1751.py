class Solution:
  def maxValue(self, events: list[list[int]], k: int) -> int:
    events.sort()

    @functools.lru_cache(None)
    def dp(i: int, k: int) -> int:
      """
      Returns the maximum sum of values that you can receive by attending
      events[i..n), where k is the maximum number of attendance.
      """
      if k == 0 or i == len(events):
        return 0

      # Binary search `events` to find the first index j
      # s.t. events[j][0] > events[i][1].
      j = bisect.bisect(events, [events[i][1], math.inf, math.inf], i + 1)
      return max(events[i][2] + dp(j, k - 1), dp(i + 1, k))

    return dp(0, k)
