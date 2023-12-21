class Solution:
  def mergeArrays(self, nums1: List[List[int]], nums2: List[List[int]]) -> List[List[int]]:
    count = [0] * (1001)
    self._addCount(nums1, count)
    self._addCount(nums2, count)
    return [[i, c] for i, c in enumerate(count) if c > 0]

  def _addCount(self, nums: List[List[int]], count: List[int]) -> None:
    for id_, val in nums:
      count[id_] += val
