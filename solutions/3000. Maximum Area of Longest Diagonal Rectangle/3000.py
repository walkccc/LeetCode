class Solution:
  def areaOfMaxDiagonal(self, dimensions: list[list[int]]) -> int:
    a, b = max(dimensions, key=lambda x: (x[0]**2 + x[1]**2, x[0] * x[1]))
    return a * b
