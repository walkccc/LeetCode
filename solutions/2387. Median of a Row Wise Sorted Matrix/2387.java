class Solution {
  public int matrixMedian(int[][] grid) {
    final int noGreaterThanMedianCount = grid.length * grid[0].length / 2 + 1;
    int l = 1;
    int r = (int) 1e6;

    while (l < r) {
      final int m = (l + r) / 2;
      if (numsNoGreaterThan(grid, m) >= noGreaterThanMedianCount)
        r = m;
      else
        l = m + 1;
    }

    return l;
  }

  private int numsNoGreaterThan(int[][] grid, int m) {
    int count = 0;
    for (int[] row : grid)
      count += firstGreater(row, m);
    return count;
  }

  private int firstGreater(int[] A, int target) {
    int l = 0;
    int r = A.length;
    while (l < r) {
      final int m = (l + r) / 2;
      if (A[m] > target)
        r = m;
      else
        l = m + 1;
    }
    return l;
  }
}
