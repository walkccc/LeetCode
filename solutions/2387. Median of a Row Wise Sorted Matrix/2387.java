class Solution {
  public int matrixMedian(int[][] grid) {
    final int noGreaterThanMedianCount = grid.length * grid[0].length / 2 + 1;
    int l = 1;
    int r = 1_000_000;

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

  private int firstGreater(int[] arr, int target) {
    int l = 0;
    int r = arr.length;
    while (l < r) {
      final int m = (l + r) / 2;
      if (arr[m] > target)
        r = m;
      else
        l = m + 1;
    }
    return l;
  }
}
