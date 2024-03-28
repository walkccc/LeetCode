class Solution:
  def pickGifts(self, gifts: List[int], k: int) -> int:
    maxHeap = [-gift for gift in gifts]
    heapq.heapify(maxHeap)

    for _ in range(k):
      squaredMax = int(sqrt(-heapq.heappop(maxHeap)))
      heapq.heappush(maxHeap, -squaredMax)

    return -sum(maxHeap)
