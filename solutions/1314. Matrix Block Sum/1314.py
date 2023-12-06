class Solution:
  def matrixBlockSum(self, mat: List[List[int]], k: int) -> List[List[int]]:
    m = len(mat)
    n = len(mat[0])
    ans = [[0] * n for _ in range(m)]
    prefix = [[0] * (n + 1) for _ in range(m + 1)]

    for i in range(m):
      for j in range(n):
        prefix[i + 1][j + 1] = mat[i][j] + \
            prefix[i][j + 1] + prefix[i + 1][j] - prefix[i][j]

    for i in range(m):
      for j in range(n):
        r1 = max(0, i - k) + 1
        c1 = max(0, j - k) + 1
        r2 = min(m - 1, i + k) + 1
        c2 = min(n - 1, j + k) + 1
        ans[i][j] = prefix[r2][c2] - prefix[r2][c1 - 1] - \
            prefix[r1 - 1][c2] + prefix[r1 - 1][c1 - 1]

    return ans
