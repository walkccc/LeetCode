class Solution:
  def findDifference(self, nums1: list[int],
                     nums2: list[int]) -> list[list[int]]:
    set1 = set(nums1)
    set2 = set(nums2)
    return [set1 - set2, set2 - set1]
