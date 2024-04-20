class Solution:
  def maxNumber(self, nums1: List[int], nums2: List[int], k: int) -> List[int]:
    def maxArray(nums: List[int], k: int) -> List[int]:
      res = []
      toTop = len(nums) - k
      for num in nums:
        while res and res[-1] < num and toTop > 0:
          res.pop()
          toTop -= 1
        res.append(num)
      return res[:k]

    def merge(nums1: List[int], nums2: List[int]) -> List[int]:
      return [max(nums1, nums2).pop(0) for _ in nums1 + nums2]

    return max(merge(maxArray(nums1, i), maxArray(nums2, k - i))
               for i in range(k + 1)
               if i <= len(nums1) and k - i <= len(nums2))
