class Solution:
  def minOperations(self, nums1: list[int], nums2: list[int]) -> int:
    n = len(nums1)
    mn = min(nums1[-1], nums2[-1])
    mx = max(nums1[-1], nums2[-1])
    # the number of the minimum operations, where nums1[n - 1] is not swapped
    # with nums2[n - 1]
    dp1 = 0
    # the number of the minimum operations, where nums1[n - 1] is swapped with
    # nums2[n - 1]
    dp2 = 0

    for a, b in zip(nums1, nums2):
      if min(a, b) > mn:
        return -1
      if max(a, b) > mx:
        return -1
      if a > nums1[-1] or b > nums2[-1]:
        dp1 += 1
      if a > nums2[-1] or b > nums1[-1]:
        dp2 += 1

    return min(dp1, dp2)
