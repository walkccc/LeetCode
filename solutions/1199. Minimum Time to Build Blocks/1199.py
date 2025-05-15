class Solution:
  def minBuildTime(self, blocks: list[int], split: int) -> int:
    minHeap = blocks.copy()
    heapify(minHeap)

    while len(minHeap) > 1:
      heapq.heappop(minHeap)  # the minimum
      x = heapq.heappop(minHeap)  # the second minimum
      heapq.heappush(minHeap, x + split)

    return minHeap[0]
