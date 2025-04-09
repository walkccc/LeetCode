class Solution {
  public int removeOnes(int[][] grid) {
    final int m = grid.length;
    final int n = grid[0].length;
    int[] mem = new int[1 << m * n];
    Arrays.fill(mem, Integer.MAX_VALUE);
    return removeOnes(encode(grid, m, n), m, n, mem);
  }

  // Returns the minimum number of operations to remove all 1s from the grid,
  // where `mask` is the bitmask of the state of the grid.
  private int removeOnes(int mask, int m, int n, int[] mem) {
    if (mask == 0)
      return 0;
    if (mem[mask] < Integer.MAX_VALUE)
      return mem[mask];

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if ((mask >> i * n + j & 1) == 1) { // grid[i][j] == 1
          int nextMask = mask;
          // Set the cells in the same row with 0.
          for (int k = 0; k < n; ++k)
            nextMask &= ~(1 << i * n + k);
          // Set the cells in the same column with 0.
          for (int k = 0; k < m; ++k)
            nextMask &= ~(1 << k * n + j);
          mem[mask] = Math.min(mem[mask], 1 + removeOnes(nextMask, m, n, mem));
        }

    return mem[mask];
  }

  private int encode(int[][] grid, int m, int n) {
    int encoded = 0;
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (grid[i][j] == 1)
          encoded |= 1 << i * n + j;
    return encoded;
  }
}
