class Solution:
  def findMaxValueOfEquation(self, points: list[list[int]], k: int) -> int:
    ans = -math.inf
    maxHeap = []  # (y - x, x)

    for x, y in points:
      while maxHeap and x + maxHeap[0][1] > k:
        heapq.heappop(maxHeap)
      if maxHeap:
        ans = max(ans, x + y - maxHeap[0][0])
      heapq.heappush(maxHeap, (x - y, -x))

    return ans
