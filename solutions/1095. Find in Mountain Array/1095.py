# """
# This is MountainArray's API interface.
# You should not implement it, or speculate about its implementation
# """
# Class MountainArray:
#   def get(self, index: int) -> int:
#   def length(self) -> int:

class Solution:
  def findInMountainArray(self, target: int, mountain_arr: 'MountainArray') -> int:
    n = mountain_arr.length()
    peakIndex = self.peakIndexInMountainArray(mountain_arr, 0, n - 1)

    leftIndex = self.searchLeft(mountain_arr, target, 0, peakIndex)
    if mountain_arr.get(leftIndex) == target:
      return leftIndex

    rightIndex = self.searchRight(mountain_arr, target, peakIndex + 1, n - 1)
    if mountain_arr.get(rightIndex) == target:
      return rightIndex

    return -1

  # 852. Peak Index in a Mountain Array
  def peakIndexInMountainArray(self, A: 'MountainArray', l: int, r: int) -> int:
    while l < r:
      m = (l + r) // 2
      if A.get(m) < A.get(m + 1):
        l = m + 1
      else:
        r = m
    return l

  def searchLeft(self, A: 'MountainArray', target: int, l: int, r: int) -> int:
    while l < r:
      m = (l + r) // 2
      if A.get(m) < target:
        l = m + 1
      else:
        r = m
    return l

  def searchRight(self, A: 'MountainArray', target: int, l: int, r: int) -> int:
    while l < r:
      m = (l + r) // 2
      if A.get(m) > target:
        l = m + 1
      else:
        r = m
    return l
