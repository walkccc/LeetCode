class Solution:
  def halveArray(self, nums: list[int]) -> int:
    halfSum = sum(nums) / 2
    ans = 0
    runningSum = 0.0
    maxHeap = [-num for num in nums]

    heapq.heapify(maxHeap)

    while runningSum < halfSum:
      maxValue = -heapq.heappop(maxHeap) / 2
      runningSum += maxValue
      heapq.heappush(maxHeap, -maxValue)
      ans += 1

    return ans
