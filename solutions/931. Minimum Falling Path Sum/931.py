class Solution:
  def minFallingPathSum(self, A: list[list[int]]) -> int:
    n = len(A)

    for i in range(1, n):
      for j in range(n):
        mn = math.inf
        for k in range(max(0, j - 1), min(n, j + 2)):
          mn = min(mn, A[i - 1][k])
        A[i][j] += mn

    return min(A[-1])
