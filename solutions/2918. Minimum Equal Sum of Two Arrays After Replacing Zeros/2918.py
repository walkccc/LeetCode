class Solution:
  def minSum(self, nums1: list[int], nums2: list[int]) -> int:
    sum1 = sum(nums1)
    sum2 = sum(nums2)
    zero1 = nums1.count(0)
    zero2 = nums2.count(0)
    if zero1 == 0 and sum1 < sum2 + zero2:
      return -1
    if zero2 == 0 and sum2 < sum1 + zero1:
      return -1
    return max(sum1 + zero1, sum2 + zero2)
