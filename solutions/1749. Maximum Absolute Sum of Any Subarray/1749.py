class Solution:
  def maxAbsoluteSum(self, nums):
    ans = -math.inf
    maxSum = 0
    minSum = 0

    for num in nums:
      maxSum = max(num, maxSum + num)
      minSum = min(num, minSum + num)
      ans = max(ans, maxSum, -minSum)

    return ans
