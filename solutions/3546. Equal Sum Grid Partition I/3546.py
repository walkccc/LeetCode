class Solution:
  def canPartitionGrid(self, grid: list[list[int]]) -> bool:
    totalSum = sum(map(sum, grid))

    def canPartition(grid: list[list[int]]) -> bool:
      runningSum = 0
      for row in grid:
        runningSum += sum(row)
        if runningSum * 2 == totalSum:
          return True
      return False

    return canPartition(grid) or canPartition(zip(*grid))
