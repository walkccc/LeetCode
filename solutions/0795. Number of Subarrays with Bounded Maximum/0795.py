class Solution:
  def numSubarrayBoundedMax(self, nums: List[int], left: int, right: int) -> int:
    ans = 0
    l = -1
    r = -1

    for i, a in enumerate(nums):
      if a > right:
        l = i
      if a >= left:
        r = i
      ans += r - l

    return ans
