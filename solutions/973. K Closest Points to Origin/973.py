class Solution:
  def kClosest(self, points: list[list[int]], k: int) -> list[list[int]]:
    maxHeap = []

    for x, y in points:
      heapq.heappush(maxHeap, (- x * x - y * y, [x, y]))
      if len(maxHeap) > k:
        heapq.heappop(maxHeap)

    return [pair[1] for pair in maxHeap]
