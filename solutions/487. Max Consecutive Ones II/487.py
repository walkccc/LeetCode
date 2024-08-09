class Solution:
  def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
    ans = 0
    zeros = 0

    l = 0
    for r, num in enumerate(nums):
      if num == 0:
        zeros += 1
      while zeros == 2:
        if nums[l] == 0:
          zeros -= 1
        l += 1
      ans = max(ans, r - l + 1)

    return ans
