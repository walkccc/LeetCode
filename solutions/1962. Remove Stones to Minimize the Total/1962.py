class Solution:
  def minStoneSum(self, piles: List[int], k: int) -> int:
    maxHeap = [-pile for pile in piles]
    heapq.heapify(maxHeap)

    for _ in range(k):
      heapq.heapreplace(maxHeap, maxHeap[0] // 2)

    return -sum(maxHeap)
