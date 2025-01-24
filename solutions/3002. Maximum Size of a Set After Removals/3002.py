class Solution:
  def maximumSetSize(self, nums1: list[int], nums2: list[int]) -> int:
    set1 = set(nums1)
    set2 = set(nums2)
    common = set1.intersection(set2)

    n = len(nums1)
    n1 = len(set1)
    n2 = len(set2)
    nc = len(common)
    maxUniqueNums1 = min(n1 - nc, n // 2)
    maxUniqueNums2 = min(n2 - nc, n // 2)
    return min(n, maxUniqueNums1 + maxUniqueNums2 + nc)
