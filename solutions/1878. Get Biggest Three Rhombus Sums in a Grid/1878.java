class Solution {
  public int[] getBiggestThree(int[][] grid) {
    final int m = grid.length;
    final int n = grid[0].length;
    TreeSet<Integer> sums = new TreeSet<>();

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        for (int sz = 0; i + sz < m && i - sz >= 0 && j + 2 * sz < n; ++sz) {
          final int sum = sz == 0 ? grid[i][j] : getSum(grid, i, j, sz);
          sums.add(sum);
          if (sums.size() > 3)
            sums.pollFirst();
        }

    return sums.descendingSet().stream().mapToInt(Integer::intValue).toArray();
  }

  // Returns the sum of the rhombus, where the top grid is (i, j) and the edge
  // size is `sz`.
  private int getSum(int[][] grid, int i, int j, int sz) {
    int x = i;
    int y = j;
    int sum = 0;

    // Go left down.
    for (int k = 0; k < sz; ++k)
      sum += grid[--x][++y];

    // Go right down.
    for (int k = 0; k < sz; ++k)
      sum += grid[++x][++y];

    // Go right up.
    for (int k = 0; k < sz; ++k)
      sum += grid[++x][--y];

    // Go left up.
    for (int k = 0; k < sz; ++k)
      sum += grid[--x][--y];

    return sum;
  }
}
