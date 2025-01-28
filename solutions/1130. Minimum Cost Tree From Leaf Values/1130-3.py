class Solution:
  def mctFromLeafValues(self, arr: list[int]) -> int:
    ans = 0

    while len(arr) > 1:
      i = arr.index(min(arr))
      ans += min(arr[i - 1:i] + arr[i + 1:i + 2]) * arr.pop(i)

    return ans
