class Solution {
  public boolean canPartitionGrid(int[][] grid) {
    final long sum = Arrays.stream(grid).flatMapToInt(Arrays::stream).asLongStream().sum();
    return canPartition(grid, sum) || canPartition(reversed(grid), sum) ||
        canPartition(reversed(transposed(grid)), sum) || canPartition(transposed(grid), sum);
  }

  private boolean canPartition(int[][] grid, long sum) {
    long topSum = 0;
    Set<Integer> seen = new HashSet<>();
    for (int i = 0; i < grid.length; ++i) {
      topSum += Arrays.stream(grid[i]).asLongStream().sum();
      final long botSum = sum - topSum;
      Arrays.stream(grid[i]).forEach(seen::add);
      if (topSum - botSum == 0 || topSum - botSum == grid[0][0] ||
          topSum - botSum == grid[0][grid[0].length - 1] || topSum - botSum == grid[i][0])
        return true;
      if (grid[0].length > 1 && i > 0 && seen.contains((int) (topSum - botSum)))
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

  private int[][] reversed(int[][] grid) {
    return Arrays.stream(grid).collect(Collectors.collectingAndThen(Collectors.toList(), list -> {
      Collections.reverse(list);
      return list.toArray(new int[0][]);
    }));
  }
}
