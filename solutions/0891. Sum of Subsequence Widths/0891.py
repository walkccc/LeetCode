class Solution:
  def sumSubseqWidths(self, A: List[int]) -> int:
    n = len(A)
    kMod = int(1e9 + 7)

    ans = 0
    exp = 1

    A.sort()

    for i in range(n):
      ans = (ans + A[i] * exp - A[n - i - 1] * exp) % kMod
      exp = exp * 2 % kMod

    return ans
