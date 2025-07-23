class Solution {
  public int countPathsWithXorValue(int[][] grid, int k) {
    final int MAX = 15;
    final int m = grid.length;
    final int n = grid[0].length;
    Integer[][][] mem = new Integer[m][n][MAX + 1];
    return count(grid, 0, 0, 0, k, mem);
  }

  private static final int MOD = 1_000_000_007;

  // Return the number of paths from (i, j) to (m - 1, n - 1) with XOR value
  // `xors`.
  private int count(int[][] grid, int i, int j, int xors, int k, Integer[][][] mem) {
    if (i == grid.length || j == grid[0].length)
      return 0;
    xors ^= grid[i][j];
    if (i == grid.length - 1 && j == grid[0].length - 1)
      return xors == k ? 1 : 0;
    if (mem[i][j][xors] != null)
      return mem[i][j][xors];
    final int right = count(grid, i, j + 1, xors, k, mem) % MOD;
    final int down = count(grid, i + 1, j, xors, k, mem) % MOD;
    return mem[i][j][xors] = (right + down) % MOD;
  }
}
