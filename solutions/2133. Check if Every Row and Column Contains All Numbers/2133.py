class Solution:
  def checkValid(self, matrix: list[list[int]]) -> bool:
    return all(min(len(set(row)), len(set(col))) == len(matrix)
               for row, col in zip(matrix, zip(*matrix)))
