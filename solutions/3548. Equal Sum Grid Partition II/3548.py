
class Solution:
  def canPartitionGrid(self, grid: list[list[int]]) -> bool:
    summ = sum(map(sum, grid))

    def canPartition(grid: list[list[int]]) -> bool:
      topSum = 0
      seen = set()
      for i, row in enumerate(grid):
        topSum += sum(row)
        botSum = summ - topSum
        seen |= set(row)
        if topSum - botSum in (0, grid[0][0],  grid[0][-1], row[0]):
          return True
        if len(grid[0]) > 1 and i > 0 and topSum - botSum in seen:
          return True
      return False

    return (canPartition(grid) or
            canPartition(grid[::-1]) or
            canPartition(list(zip(*grid))[::-1]) or
            canPartition(list(zip(*grid))))
