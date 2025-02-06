class Solution:
  def maxAlternatingSum(self, nums: list[int]) -> int:
    even = 0  # the maximum alternating sum ending in an even index
    odd = 0  # the maximum alternating sum ending in an odd index

    for num in nums:
      even = max(even, odd + num)
      odd = even - num

    return even
