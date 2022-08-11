class Solution:
  def minimumDifference(self, nums: List[int]) -> int:
    n = len(nums) // 3
    ans = math.inf
    leftSum = 0
    rightSum = 0
    maxHeap = []  # left part, as small as possible
    minHeap = []  # right part, as big as possible
    # minLeftSum[i] := min sum of n nums in nums[:i]
    minLeftSum = [0] * len(nums)

    for i in range(2 * n):
      heapq.heappush(maxHeap, -nums[i])
      leftSum += nums[i]
      if len(maxHeap) == n + 1:
        leftSum += heapq.heappop(maxHeap)
      if len(maxHeap) == n:
        minLeftSum[i] = leftSum

    for i in range(len(nums) - 1, n - 1, -1):
      heapq.heappush(minHeap, nums[i])
      rightSum += nums[i]
      if len(minHeap) == n + 1:
        rightSum -= heapq.heappop(minHeap)
      if len(minHeap) == n:
        ans = min(ans, minLeftSum[i - 1] - rightSum)

    return ans
