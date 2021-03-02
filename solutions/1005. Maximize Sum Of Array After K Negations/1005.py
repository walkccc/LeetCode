class Solution:
  def largestSumAfterKNegations(self, A: List[int], K: int) -> int:
    A.sort()

    for i in range(len(A)):
      if A[i] > 0 or K == 0:
        break
      A[i] = -A[i]
      K -= 1

    return sum(A) - (K % 2) * min(A) * 2
