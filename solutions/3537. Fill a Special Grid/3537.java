class Solution {
  public int[][] specialGrid(int n) {
    final int sz = 1 << n;
    int[][] grid = new int[sz][sz];
    fill(grid, 0, sz, 0, sz);
    return grid;
  }

  private int count = 0;

  private void fill(int[][] grid, int x1, int x2, int y1, int y2) {
    if (x2 - x1 == 1) {
      grid[x1][y1] = count++;
      return;
    }
    int midRow = (x1 + x2) / 2;
    int midCol = (y1 + y2) / 2;
    fill(grid, x1, midRow, midCol, y2);
    fill(grid, midRow, x2, midCol, y2);
    fill(grid, midRow, x2, y1, midCol);
    fill(grid, x1, midRow, y1, midCol);
  }
}
