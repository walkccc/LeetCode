class Solution:
  def peakIndexInMountainArray(self, arr: list[int]) -> int:
    l = 0
    r = len(arr) - 1

    while l < r:
      m = (l + r) // 2
      if arr[m] >= arr[m + 1]:
        r = m
      else:
        l = m + 1

    return l
