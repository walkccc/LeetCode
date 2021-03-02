class Solution:
  def searchRange(self, nums: List[int], target: int) -> List[int]:
    # find the first index l s.t nums[l] >= target
    # return nums.length if can'f firstGreaterEqual
    def firstGreaterEqual(nums, target):
      l = 0
      r = len(nums)

      while l < r:
        m = (l + r) // 2
        if nums[m] >= target:
          r = m
        else:
          l = m + 1

      return l

    start = firstGreaterEqual(nums, target)
    if start == len(nums) or nums[start] != target:
      return -1, -1
    end = firstGreaterEqual(nums, target + 1) - 1
    return start, end
