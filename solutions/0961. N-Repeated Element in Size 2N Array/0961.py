class Solution:
  def repeatedNTimes(self, A: List[int]) -> int:
    for i in range(len(A) - 2):
      if A[i] == A[i + 1] or A[i] == A[i + 2]:
        return A[i]

    return A[-1]
