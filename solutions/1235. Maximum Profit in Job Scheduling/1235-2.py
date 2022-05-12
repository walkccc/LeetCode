class Solution:
  def jobScheduling(self, startTime: List[int], endTime: List[int], profit: List[int]) -> int:
    # dp[i] := max profit to schedule jobs[i:]
    dp = [0] * (len(startTime) + 1)
    jobs = sorted([(s, e, p) for s, e, p in zip(startTime, endTime, profit)])

    # will use binary search to find the first available startTime
    for i in range(len(startTime)):
      startTime[i] = jobs[i][0]

    for i in reversed(range(len(startTime))):
      j = bisect_left(startTime, jobs[i][1])
      dp[i] = max(jobs[i][2] + dp[j], dp[i + 1])

    return dp[0]
