class Solution:
  def maximumBeauty(self, nums: List[int], k: int) -> int:
    # l and r track the maximum window instead of the valid window.
    nums.sort()

    l = 0
    for r in range(len(nums)):
      if nums[r] - nums[l] > 2 * k:
        l += 1

    return r - l + 1
