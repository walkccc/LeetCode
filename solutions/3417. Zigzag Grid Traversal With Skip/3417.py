class Solution:
  def zigzagTraversal(self, grid: list[list[int]]) -> list[int]:
    zigzag = [row[::-1] if i % 2 else row for i, row in enumerate(grid)]
    return [num for row in zigzag for num in row][::2]
