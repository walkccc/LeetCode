class Solution:
  def maximumTotalCost(self, nums: list[int]) -> int:
    keep = nums[0]  # the maximum cost if the last number is kept
    flip = nums[0]  # the maximum cost if the last number is flipped

    for i in range(1, len(nums)):
      keepCurr = max(keep, flip) + nums[i]
      flipCurr = keep - nums[i]
      keep = keepCurr
      flip = flipCurr

    return max(keep, flip)
