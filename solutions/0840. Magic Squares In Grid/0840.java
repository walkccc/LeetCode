class Solution {
  public int numMagicSquaresInside(int[][] grid) {
    int ans = 0;

    for (int i = 0; i + 2 < grid.length; ++i)
      for (int j = 0; j + 2 < grid[0].length; ++j)
        if (grid[i][j] % 2 == 0 && grid[i + 1][j + 1] == 5)
          if (isMagic(grid, i, j))
            ++ans;

    return ans;
  }

  private boolean isMagic(int[][] grid, int i, int j) {
    String s = new String("");

    for (final int num : new int[] {0, 1, 2, 5, 8, 7, 6, 3})
      s += Integer.toString(grid[i + num / 3][j + num % 3]);

    return new String("4381672943816729").contains(s) ||
           new String("9276183492761834").contains(s);
  }
}
