class Solution:
  def dominantIndex(self, nums: list[int]) -> int:
    mx = 0
    secondMax = 0

    for i, num in enumerate(nums):
      if num > mx:
        secondMax = mx
        mx = num
        ans = i
      elif num > secondMax:
        secondMax = num

    return ans if mx >= 2 * secondMax else -1
