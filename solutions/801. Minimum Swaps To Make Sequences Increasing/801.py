class Solution:
  def minSwap(self, nums1: list[int], nums2: list[int]) -> int:
    keepAt = [math.inf] * len(nums1)
    swapAt = [math.inf] * len(nums1)
    keepAt[0] = 0
    swapAt[0] = 1

    for i in range(1, len(nums1)):
      if nums1[i] > nums1[i - 1] and nums2[i] > nums2[i - 1]:
        keepAt[i] = keepAt[i - 1]
        swapAt[i] = swapAt[i - 1] + 1
      if nums1[i] > nums2[i - 1] and nums2[i] > nums1[i - 1]:
        keepAt[i] = min(keepAt[i], swapAt[i - 1])
        swapAt[i] = min(swapAt[i], keepAt[i - 1] + 1)

    return min(keepAt[-1], swapAt[-1])
