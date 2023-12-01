class Solution:
  def wiggleSort(self, nums: List[int]) -> None:
    # 1. If i is even, then nums[i] <= nums[i - 1].
    # 2. If i is odd, then nums[i] >= nums[i - 1].
    for i in range(1, len(nums)):
      if not (i & 1) and nums[i] > nums[i - 1] or \
              (i & 1) and nums[i] < nums[i - 1]:
        nums[i], nums[i - 1] = nums[i - 1], nums[i]
