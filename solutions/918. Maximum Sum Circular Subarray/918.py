class Solution:
  def maxSubarraySumCircular(self, nums: list[int]) -> int:
    totalSum = 0
    currMaxSum = 0
    currMinSum = 0
    maxSum = -math.inf
    minSum = math.inf

    for num in nums:
      totalSum += num
      currMaxSum = max(currMaxSum + num, num)
      currMinSum = min(currMinSum + num, num)
      maxSum = max(maxSum, currMaxSum)
      minSum = min(minSum, currMinSum)

    return maxSum if maxSum < 0 else max(maxSum, totalSum - minSum)
