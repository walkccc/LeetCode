class Solution:
  # Similar to 215. Kth Largest Element in an Array
  def kthLargestNumber(self, nums: List[str], k: int) -> str:
    minHeap = []

    for num in nums:
      heapq.heappush(minHeap, int(num))
      if len(minHeap) > k:
        heapq.heappop(minHeap)

    return str(minHeap[0])
