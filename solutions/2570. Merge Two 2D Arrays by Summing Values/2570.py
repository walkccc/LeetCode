class Solution:
  def mergeArrays(self, nums1: list[list[int]],
                  nums2: list[list[int]]) -> list[list[int]]:
    count = [0] * (1001)
    self._addCount(nums1, count)
    self._addCount(nums2, count)
    return [[i, c] for i, c in enumerate(count) if c > 0]

  def _addCount(self, nums: list[list[int]], count: list[int]) -> None:
    for id_, val in nums:
      count[id_] += val
