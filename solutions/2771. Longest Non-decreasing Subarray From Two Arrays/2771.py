class Solution:
  def maxNonDecreasingLength(self, nums1: List[int], nums2: List[int]) -> int:
    ans = 1
    dp1 = 1  # the longest subarray that ends in nums1[i] so far
    dp2 = 1  # the longest subarray that ends in nums2[i] so far

    for i in range(1, len(nums1)):
      dp11 = dp1 + 1 if nums1[i - 1] <= nums1[i] else 1
      dp21 = dp2 + 1 if nums2[i - 1] <= nums1[i] else 1
      dp12 = dp1 + 1 if nums1[i - 1] <= nums2[i] else 1
      dp22 = dp2 + 1 if nums2[i - 1] <= nums2[i] else 1
      dp1 = max(dp11, dp21)
      dp2 = max(dp12, dp22)
      ans = max(ans, dp1, dp2)

    return ans
