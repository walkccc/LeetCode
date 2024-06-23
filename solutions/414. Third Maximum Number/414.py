class Solution:
  def thirdMax(self, nums: List[int]) -> int:
    max1 = -math.inf  # the maximum
    max2 = -math.inf  # the second maximum
    max3 = -math.inf  # the third maximum

    for num in nums:
      if num > max1:
        max3 = max2
        max2 = max1
        max1 = num
      elif max1 > num and num > max2:
        max3 = max2
        max2 = num
      elif max2 > num and num > max3:
        max3 = num

    return max1 if max3 == -math.inf else max3
