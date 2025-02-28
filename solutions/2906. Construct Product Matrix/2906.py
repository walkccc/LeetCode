class Solution:
  def constructProductMatrix(self, grid: list[list[int]]) -> list[list[int]]:
    kMod = 12345
    m = len(grid)
    n = len(grid[0])
    ans = [[0] * n for _ in range(m)]
    prefix = [1]
    suffix = 1

    for row in grid:
      for num in row:
        prefix.append(prefix[-1] * num % kMod)

    for i in reversed(range(m)):
      for j in reversed(range(n)):
        ans[i][j] = prefix[i * n + j] * suffix % kMod
        suffix = suffix * grid[i][j] % kMod

    return ans
