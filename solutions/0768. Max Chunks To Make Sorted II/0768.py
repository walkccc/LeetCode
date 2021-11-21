class Solution:
  def maxChunksToSorted(self, arr: List[int]) -> int:
    n = len(arr)

    ans = 0
    maxi = -inf
    mini = [arr[-1]] * n

    for i in range(n - 2, -1, -1):
      mini[i] = min(mini[i + 1], arr[i])

    for i in range(n - 1):
      maxi = max(maxi, arr[i])
      if maxi <= mini[i + 1]:
        ans += 1

    return ans + 1
