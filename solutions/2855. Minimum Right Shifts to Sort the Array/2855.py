class Solution:
  def minimumRightShifts(self, nums: list[int]) -> int:
    count = 0

    for i, (a, b) in enumerate(itertools.pairwise(nums)):
      if a > b:
        count += 1
        pivot = i

    if count == 0:
      return 0
    if count > 1 or nums[-1] > nums[0]:
      return -1
    return len(nums) - pivot - 1
