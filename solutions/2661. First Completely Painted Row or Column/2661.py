class Solution:
  def firstCompleteIndex(self, arr: List[int], mat: List[List[int]]) -> int:
    m = len(mat)
    n = len(mat[0])
    # rows[i] := the number of painted grid in the i-th row
    rows = [0] * m
    # cols[j] := the number of painted grid in the j-th column
    cols = [0] * n
    # numToRow[num] := the i-th row of the `num` in the `mat`
    numToRow = [0] * (m * n + 1)
    # numToCol[num] := the j-th column of the `num` in the `mat`
    numToCol = [0] * (m * n + 1)

    for i, row in enumerate(mat):
      for j, num in enumerate(row):
        numToRow[num] = i
        numToCol[num] = j

    for i, a in enumerate(arr):
      rows[numToRow[a]] += 1
      if rows[numToRow[a]] == n:
        return i
      cols[numToCol[a]] += 1
      if cols[numToCol[a]] == m:
        return i
