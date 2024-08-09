class Solution:
  def countPairs(self, nums1: List[int], nums2: List[int]) -> int:
    ans = 0
    A = sorted([x - y for x, y in zip(nums1, nums2)])

    for i, a in enumerate(A):
      index = bisect_left(A, -a + 1)
      ans += len(A) - max(i + 1, index)

    return ans
