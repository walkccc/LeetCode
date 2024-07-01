class Solution:
  def jobScheduling(self, startTime: List[int], endTime: List[int], profit: List[int]) -> int:
    jobs = sorted([(s, e, p) for s, e, p in zip(startTime, endTime, profit)])

    # Will use binary search to find the first available startTime
    for i in range(len(startTime)):
      startTime[i] = jobs[i][0]

    @functools.lru_cache(None)
    def dp(i: int) -> int:
      """Returns the maximum profit to schedule jobs[i..n)."""
      if i == len(startTime):
        return 0
      j = bisect.bisect_left(startTime, jobs[i][1])
      return max(jobs[i][2] + dp(j), dp(i + 1))

    return dp(0)
