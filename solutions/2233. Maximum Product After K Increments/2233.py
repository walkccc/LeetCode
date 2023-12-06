class Solution:
  def maximumProduct(self, nums: List[int], k: int) -> int:
    kMod = 1_000_000_007
    ans = 1
    minHeap = nums.copy()
    heapq.heapify(minHeap)

    for _ in range(k):
      minNum = heapq.heappop(minHeap)
      heapq.heappush(minHeap, minNum + 1)

    while minHeap:
      ans *= heapq.heappop(minHeap)
      ans %= kMod

    return ans
