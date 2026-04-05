class Solution {
  public boolean canPartitionGrid(int[][] grid) {
    final long totalSum = Arrays.stream(grid).flatMapToInt(Arrays::stream).asLongStream().sum();
    return canPartition(grid, totalSum) || canPartition(transposed(grid), totalSum);
  }

  private boolean canPartition(int[][] lines, long totalSum) {
    long runningSum = 0;
    for (int[] line : lines) {
      runningSum += Arrays.stream(line).asLongStream().sum();
      if (runningSum * 2 == totalSum)
        return true;
    }
    return false;
  }

  private int[][] transposed(int[][] grid) {
    int[][] res = new int[grid[0].length][grid.length];
    for (int i = 0; i < grid.length; ++i)
      for (int j = 0; j < grid[0].length; ++j)
        res[j][i] = grid[i][j];
    return res;
  }
}
