class Solution:
  def countValidSelections(self, nums: list[int]) -> int:
    ans = 0
    prefix = 0
    suffix = sum(nums)

    for i, num in enumerate(nums):
      suffix -= num
      prefix += num
      if num > 0:
        continue
      if prefix == suffix:
        ans += 2  # Go to either direction.
      if abs(prefix - suffix) == 1:
        ans += 1  # Go to the direction with the larger sum.

    return ans
