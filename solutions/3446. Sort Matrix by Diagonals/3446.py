class Solution:
  def sortMatrix(self, grid: list[list[int]]) -> list[list[int]]:
    n = len(grid)
    ans = [[0] * n for _ in range(n)]
    diag = collections.defaultdict(list)

    for i, row in enumerate(grid):
      for j, num in enumerate(row):
        diag[i - j].append(num)

    for key in diag:
      diag[key].sort(reverse=key < 0)

    for i in range(n):
      for j in range(n):
        ans[i][j] = diag[i - j].pop()

    return ans
