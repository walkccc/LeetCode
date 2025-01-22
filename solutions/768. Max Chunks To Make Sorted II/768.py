class Solution:
  def maxChunksToSorted(self, arr: list[int]) -> int:
    n = len(arr)
    ans = 0
    mx = -math.inf
    mn = [arr[-1]] * n

    for i in reversed(range(n - 1)):
      mn[i] = min(mn[i + 1], arr[i])

    for i in range(n - 1):
      mx = max(mx, arr[i])
      if mx <= mn[i + 1]:
        ans += 1

    return ans + 1
