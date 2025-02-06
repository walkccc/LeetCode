class Solution:
  def maximumProduct(self, nums: list[int]) -> int:
    min1 = inf   # the minimum
    min2 = inf   # the second minimum
    max1 = -inf  # the maximum
    max2 = -inf  # the second maximum
    max3 = -inf  # the third maximum

    for num in nums:
      if num <= min1:
        min2 = min1
        min1 = num
      elif num <= min2:
        min2 = num

      if num >= max1:
        max3 = max2
        max2 = max1
        max1 = num
      elif num >= max2:
        max3 = max2
        max2 = num
      elif num >= max3:
        max3 = num

    return max(max1 * min1 * min2, max1 * max2 * max3)
