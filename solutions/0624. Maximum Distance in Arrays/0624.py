class Solution:
  def maxDistance(self, arrays: List[List[int]]) -> int:
    ans = 0
    mini = 10000
    maxi = -10000

    for A in arrays:
      ans = max(ans, A[-1] - mini, maxi - A[0])
      mini = min(mini, A[0])
      maxi = max(maxi, A[-1])

    return ans
