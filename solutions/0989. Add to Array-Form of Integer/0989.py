class Solution:
  def addToArrayForm(self, A: List[int], K: int) -> List[int]:
    for i in range(len(A))[::-1]:
      K, A[i] = divmod(A[i] + K, 10)

    while K > 0:
      A = [K % 10] + A
      K //= 10

    return A
