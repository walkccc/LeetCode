class Solution:
  def sortedSquares(self, A: List[int]) -> List[int]:
    n = len(A)
    l = 0
    r = n - 1
    ans = [0] * n

    while n:
      n -= 1
      if abs(A[l]) > abs(A[r]):
        ans[n] = A[l] * A[l]
        l += 1
      else:
        ans[n] = A[r] * A[r]
        r -= 1

    return ans
