class Solution:
  def minEliminationTime(self, timeReq: list[int], splitTime: int) -> int:
    minHeap = timeReq.copy()
    heapq.heapify(minHeap)
    heapq.heappop(minHeap)

    while True:
      bacterial = splitTime + heapq.heappop(minHeap)
      if not minHeap:
        return bacterial
      heapq.heappushpop(minHeap, bacterial)
