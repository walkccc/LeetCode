class Solution:
  def maxAlternatingSum(self, nums: List[int]) -> int:
    even = 0  # max alternating sum ending with a even index
    odd = 0  # max alternating sum ending with a odd index

    for num in nums:
      even = max(even, odd + num)
      odd = even - num

    return even
