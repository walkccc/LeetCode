class Solution:
  def kClosest(self, points: List[List[int]], K: int) -> List[List[int]]:
    pq = []  # max-heap

    for x, y in points:
      heapq.heappush(pq, (- x * x - y * y, [x, y]))
      if len(pq) > K:
        heapq.heappop(pq)

    return [pair[1] for pair in pq]
