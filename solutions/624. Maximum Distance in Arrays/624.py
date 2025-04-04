class Solution:
  def maxDistance(self, arrays: list[list[int]]) -> int:
    ans = 0
    mn = 10000
    mx = -10000

    for A in arrays:
      ans = max(ans, A[-1] - mn, mx - A[0])
      mn = min(mn, A[0])
      mx = max(mx, A[-1])

    return ans
