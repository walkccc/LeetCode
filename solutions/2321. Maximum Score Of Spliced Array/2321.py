class Solution:
  def maximumsSplicedArray(self, nums1: list[int], nums2: list[int]) -> int:
    def kadane(nums1: list[int], nums2: list[int]) -> int:
      """
      Returns the maximum gain of swapping some numbers in `nums1` with some
      numbers in `nums2`.
      """
      gain = 0
      maxGain = 0

      for num1, num2 in zip(nums1, nums2):
        gain = max(0, gain + num2 - num1)
        maxGain = max(maxGain, gain)

      return maxGain + sum(nums1)

    return max(kadane(nums1, nums2), kadane(nums2, nums1))
