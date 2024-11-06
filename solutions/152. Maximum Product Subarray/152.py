class Solution:
  def maxProduct(self, nums: list[int]) -> int:
    ans = nums[0]
    dpMin = nums[0]  # the minimum so far
    dpMax = nums[0]  # the maximum so far

    for i in range(1, len(nums)):
      num = nums[i]
      prevMin = dpMin  # dpMin[i - 1]
      prevMax = dpMax  # dpMax[i - 1]
      if num < 0:
        dpMin = min(prevMax * num, num)
        dpMax = max(prevMin * num, num)
      else:
        dpMin = min(prevMin * num, num)
        dpMax = max(prevMax * num, num)

      ans = max(ans, dpMax)

    return ans
