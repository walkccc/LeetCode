class Solution:
  def findClosestElements(self, arr: list[int], k: int, x: int) -> list[int]:
    l = 0
    r = len(arr) - k

    while l < r:
      m = (l + r) // 2
      if x - arr[m] <= arr[m + k] - x:
        r = m
      else:
        l = m + 1

    return arr[l:l + k]
