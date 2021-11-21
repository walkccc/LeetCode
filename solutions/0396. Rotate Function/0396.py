class Solution:
  def maxRotateFunction(self, A: List[int]) -> int:
    f = sum(i * a for i, a in enumerate(A))
    ans = f
    summ = sum(A)

    for a in reversed(A):
      f += summ - len(A) * a
      ans = max(ans, f)

    return ans
