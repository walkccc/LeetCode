class Solution:
  def maxProduct(self, nums: list[int]) -> int:
    max1 = 0
    max2 = 0

    for num in nums:
      if num > max1:
        max2, max1 = max1, num
      elif num > max2:
        max2 = num

    return (max1 - 1) * (max2 - 1)
