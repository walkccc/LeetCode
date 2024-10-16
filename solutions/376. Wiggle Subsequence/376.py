class Solution:
  def wiggleMaxLength(self, nums: list[int]) -> int:
    increasing = 1
    decreasing = 1

    for a, b in itertools.pairwise(nums):
      if b > a:
        increasing = decreasing + 1
      elif b < a:
        decreasing = increasing + 1

    return max(increasing, decreasing)
