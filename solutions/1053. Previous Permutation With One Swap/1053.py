class Solution:
  def prevPermOpt1(self, arr: List[int]) -> List[int]:
    n = len(arr)
    l = n - 2
    r = n - 1

    while l >= 0 and arr[l] <= arr[l + 1]:
      l -= 1
    if l < 0:
      return arr
    while arr[r] >= arr[l] or arr[r] == arr[r - 1]:
      r -= 1
    arr[l], arr[r] = arr[r], arr[l]

    return arr
