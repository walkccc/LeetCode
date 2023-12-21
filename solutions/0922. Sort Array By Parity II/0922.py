class Solution:
  def sortArrayByParityII(self, nums: List[int]) -> List[int]:
    n = len(nums)

    i = 0
    j = 1
    while i < n:
      while i < n and nums[i] % 2 == 0:
        i += 2
      while j < n and nums[j] % 2 == 1:
        j += 2
      if i < n:
        nums[i], nums[j] = nums[j], nums[i]

    return nums
