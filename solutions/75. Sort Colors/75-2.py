class Solution:
  def sortColors(self, nums: list[int]) -> None:
    l = 0  # The next 0 should be placed in l.
    r = len(nums) - 1  # THe next 2 should be placed in r.

    i = 0
    while i <= r:
      if nums[i] == 0:
        nums[i], nums[l] = nums[l], nums[i]
        i += 1
        l += 1
      elif nums[i] == 1:
        i += 1
      else:
        # We may swap a 0 to index i, but we're still not sure whether this 0
        # is placed in the correct index, so we can't move pointer i.
        nums[i], nums[r] = nums[r], nums[i]
        r -= 1
