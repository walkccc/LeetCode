class Solution:
  def rotate(self, matrix: list[list[int]]) -> None:
    matrix.reverse()
    for i, j in itertools.combinations(range(len(matrix)), 2):
      matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
