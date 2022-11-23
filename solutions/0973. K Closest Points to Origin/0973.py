class Solution:
  def kClosest(self, points: List[List[int]], K: int) -> List[List[int]]:
    maxHeap = []

    for x, y in points:
      heapq.heappush(maxHeap, (- x * x - y * y, [x, y]))
      if len(maxHeap) > K:
        heapq.heappop(maxHeap)

    return [pair[1] for pair in maxHeap]
