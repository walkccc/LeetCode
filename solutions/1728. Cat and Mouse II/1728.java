class Solution {
  public boolean canMouseWin(String[] grid, int catJump, int mouseJump) {
    m = grid.length;
    n = grid[0].length();
    int cat = 0;   // cat's position
    int mouse = 0; // mouse's position

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        if (grid[i].charAt(j) != '#')
          ++nFloors;
        if (grid[i].charAt(j) == 'C')
          cat = hash(i, j);
        else if (grid[i].charAt(j) == 'M')
          mouse = hash(i, j);
      }

    // dp[i][j][k] := true if the mouse can win, where the cat is on
    // (i / 8, i % 8), the mouse is on (j / 8, j % 8), and the turns = k
    dp = new Boolean[m * n][m * n][nFloors * 2];
    return canMouseWin(grid, cat, mouse, 0, catJump, mouseJump);
  }

  private static final int[] dirs = {0, 1, 0, -1, 0};
  private int m;
  private int n;
  private int nFloors = 0;
  private Boolean[][][] dp;

  private boolean canMouseWin(final String[] grid, int cat, int mouse, int turn, int catJump,
                              int mouseJump) {
    // We already search the whole touchable grid.
    if (turn == nFloors * 2)
      return false;
    if (dp[cat][mouse][turn] != null)
      return dp[cat][mouse][turn];

    if (turn % 2 == 0) {
      // the mouse's turn
      final int i = mouse / n;
      final int j = mouse % n;
      for (int k = 0; k < 4; ++k) {
        for (int jump = 0; jump <= mouseJump; ++jump) {
          final int x = i + dirs[k] * jump;
          final int y = j + dirs[k + 1] * jump;
          if (x < 0 || x == m || y < 0 || y == n)
            break;
          if (grid[x].charAt(y) == '#')
            break;
          // The mouse eats the food, so the mouse wins.
          if (grid[x].charAt(y) == 'F')
            return dp[cat][mouse][turn] = true;
          if (canMouseWin(grid, cat, hash(x, y), turn + 1, catJump, mouseJump))
            return dp[cat][mouse][turn] = true;
        }
      }
      // The mouse can't win, so the mouse loses.
      return dp[cat][mouse][turn] = false;
    } else {
      // the cat's turn
      final int i = cat / n;
      final int j = cat % n;
      for (int k = 0; k < 4; ++k) {
        for (int jump = 0; jump <= catJump; ++jump) {
          final int x = i + dirs[k] * jump;
          final int y = j + dirs[k + 1] * jump;
          if (x < 0 || x == m || y < 0 || y == n)
            break;
          if (grid[x].charAt(y) == '#')
            break;
          // The cat eats the food, so the mouse loses.
          if (grid[x].charAt(y) == 'F')
            return dp[cat][mouse][turn] = false;
          final int nextCat = hash(x, y);
          if (nextCat == mouse) // The cat catches the mouse, so the mouse loses.
            return dp[cat][mouse][turn] = false;
          if (!canMouseWin(grid, nextCat, mouse, turn + 1, catJump, mouseJump))
            return dp[cat][mouse][turn] = false;
        }
      }
      // The cat can't win, so the mouse wins.
      return dp[cat][mouse][turn] = true;
    }
  }

  private int hash(int i, int j) {
    return i * n + j;
  }
}
