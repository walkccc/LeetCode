class Solution:
  def countPairs(self, nums1: list[int], nums2: list[int]) -> int:
    ans = 0
    arr = sorted([x - y for x, y in zip(nums1, nums2)])

    for i, a in enumerate(arr):
      index = bisect_left(arr, -a + 1)
      ans += len(arr) - max(i + 1, index)

    return ans
