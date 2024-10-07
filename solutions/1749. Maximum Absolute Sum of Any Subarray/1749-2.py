class Solution:
  def maxAbsoluteSum(self, nums):
    summ = 0
    maxPrefix = 0
    minPrefix = 0

    for num in nums:
      summ += num
      maxPrefix = max(maxPrefix, summ)
      minPrefix = min(minPrefix, summ)

    return maxPrefix - minPrefix
