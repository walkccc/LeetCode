class Solution:
  def minScore(self, grid: List[List[int]]) -> List[List[int]]:
    m = len(grid)
    n = len(grid[0])
    ans = [[0] * n for _ in range(m)]
    valAndIndices = []
    rows = [0] * m  # rows[i] := the maximum used number so far
    cols = [0] * n  # cols[j] := the maximum used number so far

    for i in range(m):
      for j in range(n):
        valAndIndices.append((grid[i][j], i, j))

    valAndIndices.sort()

    for _, i, j in valAndIndices:
      nextAvailable = max(rows[i], cols[j]) + 1
      ans[i][j] = nextAvailable
      rows[i] = nextAvailable
      cols[j] = nextAvailable

    return ans
