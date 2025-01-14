class Solution:
  def maximumTotalCost(self, nums: list[int]) -> int:
    # A small trick so that we don't need to handle the edge case and can use
    # ranged-based for loop.
    keep = -math.inf  # the maximum cost if the last number is kept
    flip = 0  # the maximum cost if the last number is flipped

    for num in nums:
      keep, flip = max(keep, flip) + num, keep - num

    return max(keep, flip)
