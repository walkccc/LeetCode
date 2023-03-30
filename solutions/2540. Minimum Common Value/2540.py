class Solution:
  def getCommon(self, nums1: List[int], nums2: List[int]) -> int:
    i = 0  # nums1's index
    j = 0  # nums2's index

    while i < len(nums1) and j < len(nums2):
      if nums1[i] == nums2[j]:
        return nums1[i]
      if nums1[i] < nums2[j]:
        i += 1
      else:
        j += 1

    return -1
