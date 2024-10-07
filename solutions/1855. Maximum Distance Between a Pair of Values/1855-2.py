class Solution:
  def maxDistance(self, nums1: list[int], nums2: list[int]) -> int:
    i = 0
    j = 0

    while i < len(nums1) and j < len(nums2):
      if nums1[i] > nums2[j]:
        i += 1
      j += 1

    return 0 if i == j else j - i - 1
