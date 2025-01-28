class Solution:
  def maximumMatchingIndices(self, nums1: list[int], nums2: list[int]) -> int:
    n = len(nums1)
    ans = 0

    for shift in range(n):
      matches = 0
      for i, num2 in enumerate(nums2):
        if nums1[(i + shift) % n] == num2:
          matches += 1
      ans = max(ans, matches)

    return ans
