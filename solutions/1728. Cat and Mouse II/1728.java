class Solution {
  public boolean canMouseWin(String[] grid, int catJump, int mouseJump) {
    final int m = grid.length;
    final int n = grid[0].length();

    int cat = 0; // cat's position
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

    // dp[k][c][m] := true if mouse can win w/
    // turns = k, cat on (c / 8, c % 8), and mouse on (m / 8, m % 8)
    dp = new Boolean[nFloors * 2 + 1][64][64];

    return canMouseWin(grid, 0, cat, mouse, catJump, mouseJump) == true;
  }

  private final int[] dirs = {0, 1, 0, -1, 0};
  private int nFloors = 0;
  private Boolean[][][] dp;

  private boolean canMouseWin(
      final String[] grid, int turn, int c, int m, int catJump, int mouseJump) {
    if (dp[turn][c][m] != null)
      return dp[turn][c][m];
    // we already search whole touchable grid
    if (turn == nFloors * 2)
      return dp[turn][c][m] = false;

    if (turn % 2 == 1) {
      // cat's turn
      final int i = c / 8;
      final int j = c % 8;
      for (int k = 0; k < 4; ++k) {
        for (int jump = 0; jump <= catJump; ++jump) {
          final int x = i + dirs[k] * jump;
          final int y = j + dirs[k + 1] * jump;
          if (x < 0 || x == grid.length || y < 0 || y == grid[0].length())
            break;
          if (grid[x].charAt(y) == '#')
            break;
          if (grid[x].charAt(y) == 'F') // cat eats the food, so mouse lose
            return dp[turn][c][m] = false;
          if (hash(x, y) == m) // cat catches mouse, so mouse lose
            return dp[turn][c][m] = false;
          if (!canMouseWin(grid, turn + 1, hash(x, y), m, catJump, mouseJump))
            return dp[turn][c][m] = false;
        }
      }

      // cat can't win, so mouse win
      return dp[turn][c][m] = true;
    }

    // mouse's turn
    final int i = m / 8;
    final int j = m % 8;
    for (int k = 0; k < 4; ++k) {
      for (int jump = 0; jump <= mouseJump; ++jump) {
        final int x = i + dirs[k] * jump;
        final int y = j + dirs[k + 1] * jump;
        if (x < 0 || x == grid.length || y < 0 || y == grid[0].length())
          break;
        if (grid[x].charAt(y) == '#')
          break;
        if (grid[x].charAt(y) == 'F') // mouse eats the food, so mouse win
          return dp[turn][c][m] = true;
        if (canMouseWin(grid, turn + 1, c, hash(x, y), catJump, mouseJump))
          return dp[turn][c][m] = true;
      }
    }

    // mouse can't win, so mouse lose
    return dp[turn][c][m] = false;
  }

  private int hash(int i, int j) {
    return i * 8 + j;
  }
}
