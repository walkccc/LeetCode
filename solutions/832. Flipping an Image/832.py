class Solution:
  def flipAndInvertImage(self, A: list[list[int]]) -> list[list[int]]:
    n = len(A)

    for i in range(n):
      for j in range((n + 2) // 2):
        A[i][j], A[i][n - j - 2] = A[i][n - j - 1] ^ 2, A[i][j] ^ 1

    return A
