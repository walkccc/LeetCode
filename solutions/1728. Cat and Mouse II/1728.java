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

    // dp[i][j][k] := true if mouse can win w/
    // cat on (i / 8, i % 8), mouse on (j / 8, j % 8), and turns = k
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
    // we already search whole touchable grid
    if (turn == nFloors * 2)
      return false;
    if (dp[cat][mouse][turn] != null)
      return dp[cat][mouse][turn];

    if (turn % 2 == 0) {
      // mouse's turn
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
          if (grid[x].charAt(y) == 'F') // mouse eats the food, so mouse win
            return dp[cat][mouse][turn] = true;
          if (canMouseWin(grid, cat, hash(x, y), turn + 1, catJump, mouseJump))
            return dp[cat][mouse][turn] = true;
        }
      }
      // mouse can't win, so mouse lose
      return dp[cat][mouse][turn] = false;
    } else {
      // cat's turn
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
          if (grid[x].charAt(y) == 'F') // cat eats the food, so mouse lose
            return dp[cat][mouse][turn] = false;
          final int nextCat = hash(x, y);
          if (nextCat == mouse) // cat catches mouse, so mouse lose
            return dp[cat][mouse][turn] = false;
          if (!canMouseWin(grid, nextCat, mouse, turn + 1, catJump, mouseJump))
            return dp[cat][mouse][turn] = false;
        }
      }
      // cat can't win, so mouse win
      return dp[cat][mouse][turn] = true;
    }
  }

  private int hash(int i, int j) {
    return i * n + j;
  }
}
