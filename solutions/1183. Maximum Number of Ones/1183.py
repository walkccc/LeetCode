class Solution:
  def maximumNumberOfOnes(self, width: int, height: int, sideLength: int, maxOnes: int) -> int:
    submatrix = [[0] * sideLength for _ in range(sideLength)]

    for i in range(width):
      for j in range(height):
        submatrix[i % sideLength][j % sideLength] += 1

    return sum(heapq.nlargest(maxOnes, [a for row in submatrix for a in row]))
