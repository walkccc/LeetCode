class Solution:
  def minimumDeviation(self, nums: List[int]) -> int:
    ans = math.inf
    mini = math.inf
    maxHeap = []

    for num in nums:
      evenNum = num if num % 2 == 0 else num * 2
      heapq.heappush(maxHeap, -evenNum)
      mini = min(mini, evenNum)

    while maxHeap[0] % 2 == 0:
      maxi = -heapq.heappop(maxHeap)
      ans = min(ans, maxi - mini)
      mini = min(mini, maxi // 2)
      heapq.heappush(maxHeap, -maxi // 2)

    return min(ans, -maxHeap[0] - mini)
