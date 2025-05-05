class Solution:
  def findMaxConsecutiveOnes(self, nums: list[int]) -> int:
    ans = 0
    lastZeroIndex = -1

    l = 0
    for r, num in enumerate(nums):
      if num == 0:
        l = lastZeroIndex + 1
        lastZeroIndex = r
      ans = max(ans, r - l + 1)

    return ans
