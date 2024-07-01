class Solution:
  def makePrefSumNonNegative(self, nums: List[int]) -> int:
    ans = 0
    prefix = 0
    minHeap = []

    for num in nums:
      prefix += num
      if num < 0:
        heapq.heappush(minHeap, num)
      while prefix < 0:
        prefix -= heapq.heappop(minHeap)
        ans += 1

    return ans
