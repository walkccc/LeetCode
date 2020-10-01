class Solution {
 public:
  int cherryPickup(vector<vector<int>>& grid) {
    // the problem is identical as two people start picking cherries
    // from grid[0][0] simultaneously
    const int n = grid.size();

    vector<vector<vector<int>>> memo(n, vector<vector<int>>(n, vector<int>(n, INT_MIN)));

    // dp(x1, y1, x2) := max cherries we could pick from
    // g[x1][y1] -> g[n - 1][n - 1] + g[x2][y2] -> g[n - 1][n - 1],
    // where y2 = x1 + y1 - x2 (reduce states from 4 to 3)
    function<int(int, int, int)> dp = [&](int x1, int y1, int x2) {
      const int y2 = x1 + y1 - x2;
      if (x1 == n || y1 == n || x2 == n || y2 == n) return -1;
      if (x1 == n - 1 && y1 == n - 1) return grid[x1][y1];
      if (grid[x1][y1] == -1 || grid[x2][y2] == -1) return -1;
      int& ans = memo[x1][y1][x2];
      if (ans > INT_MIN) return ans;

      ans = max({dp(x1 + 1, y1, x2), dp(x1 + 1, y1, x2 + 1),
                 dp(x1, y1 + 1, x2), dp(x1, y1 + 1, x2 + 1)});
      if (ans == -1) return ans;

      ans += grid[x1][y1];                // do pick some cherries
      if (x1 != x2) ans += grid[x2][y2];  // two people are on different grids

      return ans;
    };

    return max(0, dp(0, 0, 0));
  }
};