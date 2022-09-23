class Solution:
  def thirdMax(self, nums: List[int]) -> int:
    minHeap = []
    seen = set()

    for num in nums:
      if num not in seen:
        seen.add(num)
        heapq.heappush(minHeap, num)
        if len(minHeap) > 3:
          heapq.heappop(minHeap)

    if len(minHeap) == 2:
      heapq.heappop(minHeap)

    return minHeap[0]
