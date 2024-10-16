class Solution:
  def transformArray(self, arr: list[int]) -> list[int]:
    if len(arr) < 3:
      return arr

    ans = []

    while ans != arr:
      ans = arr[:]
      for i in range(1, len(arr) - 1):
        if ans[i - 1] > ans[i] < ans[i + 1]:
          arr[i] += 1
        elif ans[i - 1] < ans[i] > ans[i + 1]:
          arr[i] -= 1

    return ans
