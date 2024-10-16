class Solution:
  def luckyNumbers(self, matrix: list[list[int]]) -> list[int]:
    for row in matrix:
      minIndex = row.index(min(row))
      if row[minIndex] == max(list(zip(*matrix))[minIndex]):
        return [row[minIndex]]
    return []
