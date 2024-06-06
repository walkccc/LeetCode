class Solution:
  def kSum(self, nums: List[int], k: int) -> int:
    maxSum = sum(num for num in nums if num > 0)
    absNums = sorted(abs(num) for num in nums)
    # (the next maximum sum, the next index i)
    maxHeap = [(-(maxSum - absNums[0]), 0)]
    nextMaxSum = maxSum

    for _ in range(k - 1):
      nextMaxSum, i = heapq.heappop(maxHeap)
      nextMaxSum *= -1
      if i + 1 < len(absNums):
        heapq.heappush(maxHeap, (-(nextMaxSum - absNums[i + 1]), i + 1))
        heapq.heappush(
            maxHeap, (-(nextMaxSum - absNums[i + 1] + absNums[i]), i + 1))

    return nextMaxSum
