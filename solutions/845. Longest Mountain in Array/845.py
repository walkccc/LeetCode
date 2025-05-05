class Solution:
  def longestMountain(self, arr: list[int]) -> int:
    ans = 0
    i = 0

    while i + 1 < len(arr):
      while i + 1 < len(arr) and arr[i] == arr[i + 1]:
        i += 1

      increasing = 0
      decreasing = 0

      while i + 1 < len(arr) and arr[i] < arr[i + 1]:
        increasing += 1
        i += 1

      while i + 1 < len(arr) and arr[i] > arr[i + 1]:
        decreasing += 1
        i += 1

      if increasing > 0 and decreasing > 0:
        ans = max(ans, increasing + decreasing + 1)

    return ans
