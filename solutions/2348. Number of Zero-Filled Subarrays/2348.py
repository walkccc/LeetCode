class Solution:
  def zeroFilledSubarray(self, nums: list[int]) -> int:
    ans = 0
    indexBeforeZero = -1

    for i, num in enumerate(nums):
      if num:
        indexBeforeZero = i
      else:
        ans += i - indexBeforeZero

    return ans
