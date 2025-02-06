class Solution:
  def rotate(self, matrix: list[list[int]]) -> None:
    for mn in range(len(matrix) // 2):
      mx = len(matrix) - mn - 1
      for i in range(mn, mx):
        offset = i - mn
        top = matrix[mn][i]
        matrix[mn][i] = matrix[mx - offset][mn]
        matrix[mx - offset][mn] = matrix[mx][mx - offset]
        matrix[mx][mx - offset] = matrix[i][mx]
        matrix[i][mx] = top
