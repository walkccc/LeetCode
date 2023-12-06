class Solution {
 public:
  bool canMouseWin(vector<string>& grid, int catJump, int mouseJump) {
    m = grid.size();
    n = grid[0].size();
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

    // dp[i][j][k] := true if the mouse can win, where the cat is on
    // (i / 8, i % 8), the mouse is on (j / 8, j % 8), and the turns = k
    dp.resize(m * n, vector<vector<int>>(m * n, vector<int>(nFloors * 2, -1)));
    return canMouseWin(grid, cat, mouse, 0, catJump, mouseJump);
  }

 private:
  const vector<int> dirs{0, 1, 0, -1, 0};
  int m;
  int n;
  int nFloors = 0;
  vector<vector<vector<int>>> dp;

  bool canMouseWin(const vector<string>& grid, int cat, int mouse, int turn,
                   const int& catJump, const int& mouseJump) {
    // We already search the whole touchable grid.
    if (turn == nFloors * 2)
      return false;
    if (dp[cat][mouse][turn] != -1)
      return dp[cat][mouse][turn];

    if (turn % 2 == 0) {
      // the mouse's turn
      const int i = mouse / n;
      const int j = mouse % n;
      for (int k = 0; k < 4; ++k) {
        for (int jump = 0; jump <= mouseJump; ++jump) {
          const int x = i + dirs[k] * jump;
          const int y = j + dirs[k + 1] * jump;
          if (x < 0 || x == m || y < 0 || y == n)
            break;
          if (grid[x][y] == '#')
            break;
          // The mouse eats the food, so the mouse wins.
          if (grid[x][y] == 'F')
            return dp[cat][mouse][turn] = true;
          if (canMouseWin(grid, cat, hash(x, y), turn + 1, catJump, mouseJump))
            return dp[cat][mouse][turn] = true;
        }
      }
      // The mouse can't win, so the mouse loses.
      return dp[cat][mouse][turn] = false;
    } else {
      // the cat's turn
      const int i = cat / n;
      const int j = cat % n;
      for (int k = 0; k < 4; ++k) {
        for (int jump = 0; jump <= catJump; ++jump) {
          const int x = i + dirs[k] * jump;
          const int y = j + dirs[k + 1] * jump;
          if (x < 0 || x == m || y < 0 || y == n)
            break;
          if (grid[x][y] == '#')
            break;
          // The cat eats the food, so the mouse loses.
          if (grid[x][y] == 'F')
            return dp[cat][mouse][turn] = false;
          const int nextCat = hash(x, y);
          // The cat catches the mouse, so the mouse loses.
          if (nextCat == mouse)
            return dp[cat][mouse][turn] = false;
          if (!canMouseWin(grid, nextCat, mouse, turn + 1, catJump, mouseJump))
            return dp[cat][mouse][turn] = false;
        }
      }
      // The cat can't win, so the mouse wins.
      return dp[cat][mouse][turn] = true;
    }
  }

  int hash(int i, int j) {
    return i * n + j;
  }
};
