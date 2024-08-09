class Solution:
  def maxChunksToSorted(self, arr: List[int]) -> int:
    ans = 0
    mx = -math.inf

    for i, a in enumerate(arr):
      mx = max(mx, a)
      if mx == i:
        ans += 1

    return ans
