class Solution:
  def isMajorityElement(self, nums: list[int], target: int) -> bool:
    n = len(nums)
    i = bisect.bisect_left(nums, target)
    return i + n // 2 < n and nums[i + n // 2] == target
