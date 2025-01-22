class Solution:
  def restoreMatrix(self, rowSum: list[int],
                    colSum: list[int]) -> list[list[int]]:
    m = len(rowSum)
    n = len(colSum)
    ans = [[0] * n for _ in range(m)]

    for i in range(m):
      for j in range(n):
        ans[i][j] = min(rowSum[i], colSum[j])
        rowSum[i] -= ans[i][j]
        colSum[j] -= ans[i][j]

    return ans
