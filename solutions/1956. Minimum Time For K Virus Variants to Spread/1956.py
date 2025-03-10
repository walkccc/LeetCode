class Solution:
  def minDayskVariants(self, points: list[list[int]], k: int) -> int:
    MAX = 100
    ans = math.inf

    for a in range(1, MAX + 1):
      for b in range(1, MAX + 1):
        # Stores the k minimum distances of points that can reach (a, b).
        maxHeap = []
        for x, y in points:
          heapq.heappush(maxHeap, -abs(x - a) + -abs(y - b))
          if len(maxHeap) > k:
            heapq.heappop(maxHeap)
        ans = min(ans, -maxHeap[0])

    return ans
