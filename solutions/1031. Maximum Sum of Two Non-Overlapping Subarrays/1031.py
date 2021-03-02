class Solution:
  def maxSumTwoNoOverlap(self, A: List[int], L: int, M: int) -> int:
    def helper(l: int, r: int) -> int:
      n = len(A)

      left = [0] * n
      sum = 0

      for i in range(n):
        sum += A[i]
        if i >= l:
          sum -= A[i - l]
        if i >= l - 1:
          left[i] = max(left[i - 1], sum) if i > 0 else sum

      right = [0] * n
      sum = 0

      for i in range(n)[::-1]:
        sum += A[i]
        if i <= n - r - 1:
          sum -= A[i + r]
        if i <= n - r:
          right[i] = max(right[i + 1], sum) if i < n - 1 else sum

      return max(left[i] + right[i + 1] for i in range(n - 1))

    return max(helper(L, M), helper(M, L))
