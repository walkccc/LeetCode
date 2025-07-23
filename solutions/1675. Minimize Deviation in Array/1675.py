class Solution:
  def minimumDeviation(self, nums: list[int]) -> int:
    ans = math.inf
    mn = math.inf
    maxHeap = []

    for num in nums:
      evenNum = num if num % 2 == 0 else num * 2
      heapq.heappush(maxHeap, -evenNum)
      mn = min(mn, evenNum)

    while maxHeap[0] % 2 == 0:
      mx = -heapq.heappop(maxHeap)
      ans = min(ans, mx - mn)
      mn = min(mn, mx // 2)
      heapq.heappush(maxHeap, -mx // 2)

    return min(ans, -maxHeap[0] - mn)
