class Solution:
  def missingNumber(self, arr: List[int]) -> int:
    n = len(arr)
    delta = (arr[-1] - arr[0]) // n
    l = 0
    r = n - 1

    while l < r:
      m = (l + r) // 2
      if arr[m] == arr[0] + m * delta:
        l = m + 1
      else:
        r = m

    return arr[0] + l * delta
