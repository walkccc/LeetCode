class Solution {
  public int numberOfPaths(int[][] grid, int k) {
    Integer[][][] mem = new Integer[grid.length][grid[0].length][k];
    return numberOfPaths(grid, 0, 0, 0, k, mem);
  }

  private static final int kMod = 1_000_000_007;

  // Returns the number of paths to (i, j), where the sum / k == `sum`.
  private int numberOfPaths(int[][] grid, int i, int j, int sum, int k, Integer[][][] mem) {
    if (i == grid.length || j == grid[0].length)
      return 0;
    if (i == grid.length - 1 && j == grid[0].length - 1)
      return (sum + grid[i][j]) % k == 0 ? 1 : 0;
    if (mem[i][j][sum] != null)
      return mem[i][j][sum];
    final int newSum = (sum + grid[i][j]) % k;
    return mem[i][j][sum] = (numberOfPaths(grid, i + 1, j, newSum, k, mem) +
                             numberOfPaths(grid, i, j + 1, newSum, k, mem)) %
                            kMod;
  }
}
