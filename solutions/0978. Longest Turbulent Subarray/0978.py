class Solution:
  def maxTurbulenceSize(self, A: List[int]) -> int:
    ans = 1
    increasing = 1
    decreasing = 1

    for i in range(1, len(A)):
      if A[i] > A[i - 1]:
        increasing = decreasing + 1
        decreasing = 1
      elif A[i] < A[i - 1]:
        decreasing = increasing + 1
        increasing = 1
      else:
        increasing = 1
        decreasing = 1
      ans = max(ans, max(increasing, decreasing))

    return ans
