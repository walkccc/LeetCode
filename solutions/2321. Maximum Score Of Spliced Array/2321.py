class Solution:
  def maximumsSplicedArray(self, nums1: List[int], nums2: List[int]) -> int:
      # how much nums1 can gain by swapping a part of the array
    def kadane(nums1: List[int], nums2: List[int]) -> int:
      gain = 0
      maxGain = 0

      for n1, n2 in zip(nums1, nums2):
        gain = max(0, gain + n2 - n1)
        maxGain = max(maxGain, gain)

      return maxGain + sum(nums1)

    return max(kadane(nums1, nums2), kadane(nums2, nums1))
