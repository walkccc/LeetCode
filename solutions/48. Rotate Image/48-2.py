class Solution:
  def rotate(self, matrix: List[List[int]]) -> None:
    for min in range(len(matrix) // 2):
      max = len(matrix) - min - 1
      for i in range(min, max):
        offset = i - min
        top = matrix[min][i]
        matrix[min][i] = matrix[max - offset][min]
        matrix[max - offset][min] = matrix[max][max - offset]
        matrix[max][max - offset] = matrix[i][max]
        matrix[i][max] = top
