class Solution:
  def minOperations(self, nums: list[int], k: int) -> int:
    ans = 0
    minHeap = nums.copy()
    heapq.heapify(minHeap)

    while len(minHeap) > 1 and minHeap[0] < k:
      x = heapq.heappop(minHeap)
      y = heapq.heappop(minHeap)
      heapq.heappush(minHeap, min(x, y) * 2 + max(x, y))
      ans += 1

    return ans
