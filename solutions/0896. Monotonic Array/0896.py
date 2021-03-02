class Solution:
  def isMonotonic(self, A: List[int]) -> bool:
    increasing = True
    decreasing = True

    for i in range(1, len(A)):
      increasing &= A[i - 1] <= A[i]
      decreasing &= A[i - 1] >= A[i]

    return increasing or decreasing
