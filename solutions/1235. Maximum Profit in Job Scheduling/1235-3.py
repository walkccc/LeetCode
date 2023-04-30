class Solution:
  def jobScheduling(self, startTime: List[int], endTime: List[int], profit: List[int]) -> int:
    maxProfit = 0
    jobs = sorted([(s, e, p) for s, e, p in zip(startTime, endTime, profit)])
    minHeap = []  # (endTime, profit)

    # Will use binary search to find the first available startTime
    for i in range(len(startTime)):
      startTime[i] = jobs[i][0]

    for s, e, p in jobs:
      while minHeap and s >= minHeap[0][0]:
        maxProfit = max(maxProfit, heapq.heappop(minHeap)[1])
      heapq.heappush(minHeap, (e, p + maxProfit))

    return max(maxProfit, max(p for _, p in minHeap))
