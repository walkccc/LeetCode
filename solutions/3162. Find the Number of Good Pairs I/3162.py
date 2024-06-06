class Solution:
  def numberOfPairs(self, nums1: List[int], nums2: List[int], k: int) -> int:
    return sum(num1 % (num2 * k) == 0
               for num1 in nums1
               for num2 in nums2)
