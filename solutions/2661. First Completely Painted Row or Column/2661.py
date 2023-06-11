class Solution:
  def firstCompleteIndex(self, arr: List[int], mat: List[List[int]]) -> int:
    m = len(mat)
    n = len(mat[0])
    # rows[i] := # of painted grid in i-th row
    rows = [0] * m
    # cols[j] := # of painted grid in j-th col
    cols = [0] * n
    # numToRow[num] := i-th row of num in mat
    numToRow = [0] * (m * n + 1)
    # numToCol[num] := j-th col of num in mat
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
    