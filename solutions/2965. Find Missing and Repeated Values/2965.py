class Solution:
  def findMissingAndRepeatedValues(self, grid: list[list[int]]) -> list[int]:
    count = [1] + [0] * len(grid)**2  # padding for 1-indexed

    for row in grid:
      for num in row:
        count[num] += 1

    return [count.index(2), count.index(0)]
