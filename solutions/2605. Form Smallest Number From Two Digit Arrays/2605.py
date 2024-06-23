class Solution:
  def minNumber(self, nums1: List[int], nums2: List[int]) -> int:
    return min(a if a == b else min(a, b) * 10 + max(a, b)
               for a in nums1
               for b in nums2)
