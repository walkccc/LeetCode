class Solution {
  public int minimumOperations(int[][] grid) {
    final int m = grid.length;
    final int n = grid[0].length;
    int[][] count = new int[n][10];

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        ++count[j][grid[i][j]];

    Integer[][] mem = new Integer[n][10];
    return minimumOperations(count, 0, 0, m, mem);
  }

  // Returns the number of minimum operations needed to make grid[:][j..n)
  // satisfy the conditions, where the (j - 1)-th column is filled with `prev`.
  private int minimumOperations(int[][] count, int j, int prev, int m, Integer[][] mem) {
    if (j == count.length)
      return 0;
    if (mem[j][prev] != null)
      return mem[j][prev];

    int res = Integer.MAX_VALUE;

    for (int num = 0; num < 10; ++num)
      if (j == 0 || num != prev)
        res = Math.min(res, m - count[j][num] + minimumOperations(count, j + 1, num, m, mem));

    return mem[j][prev] = res;
  }
}
