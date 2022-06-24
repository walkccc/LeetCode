class Solution:
  def smallestRangeII(self, A: List[int], K: int) -> int:
    A.sort()

    ans = A[-1] - A[0]
    left = A[0] + K
    right = A[-1] - K

    for a, b in zip(A, A[1:]):
      mini = min(left, b - K)
      maxi = max(right, a + K)
      ans = min(ans, maxi - mini)

    return ans
