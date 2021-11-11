class Solution:
  def jobScheduling(self, startTime: List[int], endTime: List[int], profit: List[int]) -> int:
    maxProfit = 0
    jobs = sorted([(s, e, p) for s, e, p in zip(startTime, endTime, profit)])
    pq = []  # (endTime, profit)

    # will use binary search to find the first available startTime
    for i in range(len(startTime)):
      startTime[i] = jobs[i][0]

    for s, e, p in jobs:
      while pq and s >= pq[0][0]:
        maxProfit = max(maxProfit, heapq.heappop(pq)[1])
      heapq.heappush(pq, (e, p + maxProfit))

    return max(maxProfit, max(p for _, p in pq))
