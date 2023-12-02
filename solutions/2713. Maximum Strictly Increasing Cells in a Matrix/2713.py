class Solution:
  def maxIncreasingCells(self, mat: List[List[int]]) -> int:
    m = len(mat)
    n = len(mat[0])
    rows = [0] * m  # rows[i] := the maximum path length for the i-th row
    cols = [0] * n  # cols[j] := the maximum path length for the j-th column
    valToIndices = collections.defaultdict(list)
    # maxPathLength[i][j] := the maximum path length from mat[i][j]
    maxPathLength = [[0] * n for _ in range(m)]
    # Sort all the unique values in the matrix in non-increasing order.
    decreasingSet = set()

    for i in range(m):
      for j in range(n):
        val = mat[i][j]
        valToIndices[val].append((i, j))
        decreasingSet.add(val)

    for val in sorted(decreasingSet, reverse=True):
      for i, j in valToIndices[val]:
        maxPathLength[i][j] = max(rows[i], cols[j]) + 1
      for i, j in valToIndices[val]:
        rows[i] = max(rows[i], maxPathLength[i][j])
        cols[j] = max(cols[j], maxPathLength[i][j])

    return max(max(rows), max(cols))
