class Solution {
  public boolean checkValidGrid(int[][] grid) {
    final int n = grid.length;
    int i = 0;
    int j = 0;

    for (int target = 1; target < n * n; ++target) {
      Pair<Integer, Integer> pair = nextGrid(grid, i, j, target);
      final int x = pair.getKey();
      final int y = pair.getValue();
      if (x == -1 && y == -1)
        return false;
      // Move (x, y) to (i, j).
      i = x;
      j = y;
    }

    return true;
  }

  private static final int[][] dirs = {{-2, 1}, {-1, 2}, {1, 2},   {2, 1},
                                       {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};

  // Returns (x, y), where grid[x][y] == target if (i, j) can reach target.
  private Pair<Integer, Integer> nextGrid(int[][] grid, int i, int j, int target) {
    final int n = grid.length;
    for (int[] dir : dirs) {
      final int x = i + dir[0];
      final int y = j + dir[1];
      if (x < 0 || x >= n || y < 0 || y >= n)
        continue;
      if (grid[x][y] == target)
        return new Pair<>(x, y);
    }
    return new Pair<>(-1, -1);
  }
}
