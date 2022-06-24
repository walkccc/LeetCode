class Solution:
  def sortArrayByParity(self, A: List[int]) -> List[int]:
    l = 0
    r = len(A) - 1

    while l < r:
      if A[l] % 2 == 1 and A[r] % 2 == 0:
        A[l], A[r] = A[r], A[l]
      if A[l] % 2 == 0:
        l += 1
      if A[r] % 2 == 1:
        r -= 1

    return A
