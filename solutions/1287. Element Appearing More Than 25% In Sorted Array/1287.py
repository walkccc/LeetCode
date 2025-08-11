class Solution:
  def findSpecialInteger(self, arr: list[int]) -> int:
    n = len(arr)
    quarter = n // 4

    for i in range(n - quarter):
      if arr[i] == arr[i + quarter]:
        return arr[i]
