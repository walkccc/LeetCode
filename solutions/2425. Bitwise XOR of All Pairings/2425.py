class Solution:
  def xorAllNums(self, nums1: list[int], nums2: list[int]) -> int:
    xors1 = functools.reduce(operator.xor, nums1)
    xors2 = functools.reduce(operator.xor, nums2)
    # If the size of nums1 is m and the size of nums2 is n, then each number in
    # nums1 is repeated n times and each number in nums2 is repeated m times.
    return (len(nums1) % 2 * xors2) ^ (len(nums2) % 2 * xors1)
