class Solution:
  def minFallingPathSum(self, A: List[List[int]]) -> int:
    n = len(A)

    for i in range(1, n):
      for j in range(n):
        mini = math.inf
        for k in range(max(0, j - 1), min(n, j + 2)):
          mini = min(mini, A[i - 1][k])
        A[i][j] += mini

    return min(A[-1])
