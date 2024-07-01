class Solution:
  def luckyNumbers(self, matrix: List[List[int]]) -> List[int]:
    for row in matrix:
      minIndex = row.index(min(row))
      if row[minIndex] == max(list(zip(*matrix))[minIndex]):
        return [row[minIndex]]
    return []
