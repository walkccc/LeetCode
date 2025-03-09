class Solution:
  def maxTurbulenceSize(self, arr: list[int]) -> int:
    ans = 1
    increasing = 1
    decreasing = 1

    for i in range(1, len(arr)):
      if arr[i] > arr[i - 1]:
        increasing = decreasing + 1
        decreasing = 1
      elif arr[i] < arr[i - 1]:
        decreasing = increasing + 1
        increasing = 1
      else:
        increasing = 1
        decreasing = 1
      ans = max(ans, max(increasing, decreasing))

    return ans
