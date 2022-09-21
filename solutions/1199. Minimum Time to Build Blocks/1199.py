class Solution:
  def minBuildTime(self, blocks: List[int], split: int) -> int:
    minHeap = blocks.copy()
    heapify(minHeap)

    while len(minHeap) > 1:
      heapq.heappop(minHeap)  # smallest
      x = heapq.heappop(minHeap)  # 2nd smallest
      heapq.heappush(minHeap, x + split)

    return minHeap[0]
