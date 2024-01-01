class Solution:
  def numSubarrayBoundedMax(self, nums: List[int], left: int, right: int) -> int:
    ans = 0
    l = -1
    r = -1

    for i, num in enumerate(nums):
      if num > right:  # Handle the reset value.
        l = i
      if num >= left:  # Handle the reset and the needed value.
        r = i
      ans += r - l

    return ans
