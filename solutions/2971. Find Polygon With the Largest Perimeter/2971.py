class Solution:
  def largestPerimeter(self, nums: list[int]) -> int:
    prefix = sum(nums)

    for num in sorted(nums, reverse=True):
      prefix -= num
      # Let `num` be the longest side. Check if the sum of all the edges with
      # length no longer than `num` > `num``.
      if prefix > num:
        return prefix + num

    return -1
