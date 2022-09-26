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

    // dp[i][j][k] := true if mouse can win w/
    // cat on (i / 8, i % 8), mouse on (j / 8, j % 8), and turns = k
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
    // we already search whole touchable grid
    if (turn == nFloors * 2)
      return false;
    if (dp[cat][mouse][turn] != -1)
      return dp[cat][mouse][turn];

    if (turn % 2 == 0) {
      // mouse's turn
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
          if (grid[x][y] == 'F')  // mouse eats the food, so mouse win
            return dp[cat][mouse][turn] = true;
          if (canMouseWin(grid, cat, hash(x, y), turn + 1, catJump, mouseJump))
            return dp[cat][mouse][turn] = true;
        }
      }
      // mouse can't win, so mouse lose
      return dp[cat][mouse][turn] = false;
    } else {
      // cat's turn
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
          if (grid[x][y] == 'F')  // cat eats the food, so mouse lose
            return dp[cat][mouse][turn] = false;
          const int nextCat = hash(x, y);
          if (nextCat == mouse)  // cat catches mouse, so mouse lose
            return dp[cat][mouse][turn] = false;
          if (!canMouseWin(grid, nextCat, mouse, turn + 1, catJump, mouseJump))
            return dp[cat][mouse][turn] = false;
        }
      }
      // cat can't win, so mouse win
      return dp[cat][mouse][turn] = true;
    }
  }

  int hash(int i, int j) {
    return i * n + j;
  }
};
