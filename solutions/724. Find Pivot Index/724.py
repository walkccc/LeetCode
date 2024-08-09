class Solution:
  def pivotIndex(self, nums: List[int]) -> int:
    summ = sum(nums)
    prefix = 0

    for i, num in enumerate(nums):
      if prefix == summ - prefix - num:
        return i
      prefix += num

    return -1
