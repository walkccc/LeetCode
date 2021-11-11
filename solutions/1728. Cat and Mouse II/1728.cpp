class Solution {
 public:
  bool canMouseWin(vector<string>& grid, int catJump, int mouseJump) {
    const int m = grid.size();
    const int n = grid[0].size();

    int cat;    // cat's position
    int mouse;  // mouse's position

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] != '#')
          ++nFloors;
        if (grid[i][j] == 'C')
          cat = hash(i, j);
        else if (grid[i][j] == 'M')
          mouse = hash(i, j);
      }

    // dp[k][c][m] := true if mouse can win w/
    // turns = k, cat on (c / 8, c % 8), and mouse on (m / 8, m % 8)
    dp.resize(nFloors * 2 + 1, vector<vector<int>>(64, vector<int>(64, -1)));

    return canMouseWin(grid, 0, cat, mouse, catJump, mouseJump);
  }

 private:
  const vector<int> dirs{0, 1, 0, -1, 0};
  int nFloors = 0;
  vector<vector<vector<int>>> dp;

  bool canMouseWin(const vector<string>& grid, int turn, int c, int m,
                   const int& catJump, const int& mouseJump) {
    if (dp[turn][c][m] != -1)
      return dp[turn][c][m];
    // we already search whole touchable grid
    if (turn == nFloors * 2)
      return dp[turn][c][m] = false;

    if (turn & 1) {
      // cat's turn
      const int i = c / 8;
      const int j = c % 8;
      for (int k = 0; k < 4; ++k) {
        for (int jump = 0; jump <= catJump; ++jump) {
          const int x = i + dirs[k] * jump;
          const int y = j + dirs[k + 1] * jump;
          if (x < 0 || x == grid.size() || y < 0 || y == grid[0].size())
            break;
          if (grid[x][y] == '#')
            break;
          if (grid[x][y] == 'F')  // cat eats the food, so mouse lose
            return dp[turn][c][m] = false;
          if (hash(x, y) == m)  // cat catches mouse, so mouse lose
            return dp[turn][c][m] = false;
          if (!canMouseWin(grid, turn + 1, hash(x, y), m, catJump, mouseJump))
            return dp[turn][c][m] = false;
        }
      }

      // cat can't win, so mouse win
      return dp[turn][c][m] = true;
    }

    // mouse's turn
    const int i = m / 8;
    const int j = m % 8;
    for (int k = 0; k < 4; ++k) {
      for (int jump = 0; jump <= mouseJump; ++jump) {
        const int x = i + dirs[k] * jump;
        const int y = j + dirs[k + 1] * jump;
        if (x < 0 || x == grid.size() || y < 0 || y == grid[0].size())
          break;
        if (grid[x][y] == '#')
          break;
        if (grid[x][y] == 'F')  // mouse eats the food, so mouse win
          return dp[turn][c][m] = true;
        if (canMouseWin(grid, turn + 1, c, hash(x, y), catJump, mouseJump))
          return dp[turn][c][m] = true;
      }
    }

    // mouse can't win, so mouse lose
    return dp[turn][c][m] = false;
  }

  int hash(int i, int j) {
    return i * 8 + j;
  }
};
