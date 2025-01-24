class Solution:
  def maximumBeauty(self, nums: list[int], k: int) -> int:
    nums.sort()

    # l and r track the maximum window instead of the valid window.
    l = 0
    for r in range(len(nums)):
      if nums[r] - nums[l] > 2 * k:
        l += 1

    return r - l + 1
