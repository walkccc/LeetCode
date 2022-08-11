class Solution:
  def prevPermOpt1(self, A: List[int]) -> List[int]:
    n = len(A)
    l = n - 2
    r = n - 1

    while l >= 0 and A[l] <= A[l + 1]:
      l -= 1
    if l < 0:
      return A
    while A[r] >= A[l] or A[r] == A[r - 1]:
      r -= 1
    A[l], A[r] = A[r], A[l]

    return A
