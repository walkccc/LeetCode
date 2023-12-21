class Solution:
  def maxValue(self, events: List[List[int]], k: int) -> int:
    e = sorted(events)

    @functools.lru_cache(None)
    def dp(i, k):
      """
      Returns the maximum sum of values that you can receive by attending the
      events[i..n), where k is the maximum number of attendance.
      """
      if k == 0 or i == len(e):
        return 0

      # Binary search events to find the first index j s.t. e[j][0] > e[i][1].
      j = bisect.bisect(e, [e[i][1], math.inf, math.inf], i + 1)
      return max(dp(i + 1, k), e[i][2] + dp(j, k - 1))

    return dp(0, k)
