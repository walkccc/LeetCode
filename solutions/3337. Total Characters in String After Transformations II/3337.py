class Solution:
  # Similar to 3335. Total Characters in String After Transformations I
  def lengthAfterTransformations(self, s: str, t: int, nums: list[int]) -> int:
    MOD = 1_000_000_007

    def matrixMult(A: list[list[int]], B: list[list[int]]) -> list[list[int]]:
      """Returns A * B."""
      sz = len(A)
      C = [[0] * sz for _ in range(sz)]
      for i in range(sz):
        for j in range(sz):
          for k in range(sz):
            C[i][j] += A[i][k] * B[k][j]
            C[i][j] %= MOD
      return C

    def matrixPow(M: list[list[int]], n: int) -> list[list[int]]:
      """Returns M^n."""
      if n == 0:
        return [[1 if i == j else 0  # identity matrix
                for j in range(len(M))]
                for i in range(len(M))]
      if n % 2 == 1:
        return matrixMult(M, matrixPow(M, n - 1))
      return matrixPow(matrixMult(M, M), n // 2)

    # T[i][j] := the number of ways to transform ('a' + i) to ('a' + j)
    T = self._getTransformationMatrix(nums)
    poweredT = matrixPow(T, t)
    count = [0] * 26
    lengths = [0] * 26

    for c in s:
      count[ord(c) - ord('a')] += 1

    for i in range(26):
      for j in range(26):
        lengths[j] += count[i] * poweredT[i][j]
        lengths[j] %= MOD

    return sum(lengths) % MOD

  def _getTransformationMatrix(self, nums: list[int]) -> list[list[int]]:
    T = [[0] * 26 for _ in range(26)]
    for i, steps in enumerate(nums):
      for step in range(1, steps + 1):
        T[i][(i + step) % 26] += 1
    return T
