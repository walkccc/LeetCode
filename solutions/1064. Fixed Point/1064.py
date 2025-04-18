class Solution:
  def fixedPoint(self, arr: list[int]) -> int:
    l = 0
    r = len(arr) - 1

    # Since arr[i] is strictly increasing, arr[i] - i will also be increasing.
    # Therefore, binary search `arr` for the first arr[i] - i = 0.
    while l < r:
      m = (l + r) // 2
      if arr[m] - m >= 0:
        r = m
      else:
        l = m + 1

    return l if arr[l] == l else -1
