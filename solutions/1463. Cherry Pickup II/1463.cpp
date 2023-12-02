class Solution {
 public:
  int cherryPickup(vector<vector<int>>& grid) {
    this->m = grid.size();
    this->n = grid[0].size();
    // dp[x][y1][y2] := the maximum cherries we can collect, where the robot #1
    // is on (x, y1) and the robot #2 is on (x, y2)
    dp.resize(m, vector<vector<int>>(n, vector<int>(n, -1)));
    return cherryPick(grid, 0, 0, n - 1);
  }

 private:
  int m;
  int n;
  vector<vector<vector<int>>> dp;

  int cherryPick(const vector<vector<int>>& grid, int x, int y1, int y2) {
    if (x == m)
      return 0;
    if (y1 < 0 || y1 == n || y2 < 0 || y2 == n)
      return 0;
    if (dp[x][y1][y2] != -1)
      return dp[x][y1][y2];

    const int currRow = grid[x][y1] + (y1 != y2) * grid[x][y2];

    for (int d1 = -1; d1 <= 1; ++d1)
      for (int d2 = -1; d2 <= 1; ++d2)
        dp[x][y1][y2] = max(
            dp[x][y1][y2], currRow + cherryPick(grid, x + 1, y1 + d1, y2 + d2));

    return dp[x][y1][y2];
  }
};
