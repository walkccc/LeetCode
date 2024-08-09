class Solution:
  def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
    l = 0
    r = len(arr) - k

    while l < r:
      m = (l + r) // 2
      if x - arr[m] <= arr[m + k] - x:
        r = m
      else:
        l = m + 1

    return arr[l:l + k]
