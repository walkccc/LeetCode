class Solution {
 public:
  int cherryPickup(vector<vector<int>>& grid) {
    // the problem is identical as two people start picking cherries
    // from grid[0][0] simultaneously
    n = grid.size();
    // dp[x1][y1][x2] := max cherries we could pick from
    // g[0][0] -> g[x1 - 1][y1 - 1] + g[0][0] -> g[x2 - 1][y2 - 1],
    // where y2 = x1 + y1 - x2 (reduce states from 4 to 3)
    dp.resize(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, INT_MIN)));
    return max(0, cherryPickup(grid, 0, 0, 0));
  }

 private:
  int n;
  vector<vector<vector<int>>> dp;

  int cherryPickup(const vector<vector<int>>& grid, int x1, int y1, int x2) {
    const int y2 = x1 + y1 - x2;
    if (x1 == n || y1 == n || x2 == n || y2 == n)
      return -1;
    if (x1 == n - 1 && y1 == n - 1)
      return grid[x1][y1];
    if (grid[x1][y1] == -1 || grid[x2][y2] == -1)
      return -1;
    int& ans = dp[x1][y1][x2];
    if (ans > INT_MIN)
      return ans;

    ans = max({cherryPickup(grid, x1 + 1, y1, x2),
               cherryPickup(grid, x1 + 1, y1, x2 + 1),
               cherryPickup(grid, x1, y1 + 1, x2),
               cherryPickup(grid, x1, y1 + 1, x2 + 1)});
    if (ans == -1)
      return ans;

    ans += grid[x1][y1];  // do pick some cherries
    if (x1 != x2)         // two people are on different grids
      ans += grid[x2][y2];

    return ans;
  }
};
