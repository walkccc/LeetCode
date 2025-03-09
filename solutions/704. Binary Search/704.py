class Solution:
  def search(self, nums: list[int], target: int) -> int:
    i = bisect.bisect_left(nums, target)
    return -1 if i == len(nums) or nums[i] != target else i
