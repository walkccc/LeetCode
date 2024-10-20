from sortedcontainers import SortedList


class Solution:
  def advantageCount(self, nums1: list[int], nums2: list[int]) -> list[int]:
    sl = SortedList(nums1)

    for i, num in enumerate(nums2):
      index = 0 if sl[-1] <= num else sl.bisect_right(num)
      nums1[i] = sl[index]
      del sl[index]

    return nums1
