class Solution {
 public:
  int cherryPickup(vector<vector<int>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();

    vector<vector<vector<int>>> memo(m, vector<vector<int>>(n, vector<int>(n, -1)));

    // dp(x, y1, y2) := max cherries we can collect with
    // robot #1 on (x, y1) and robot #2 on (x, y2) first
    function<int(int, int, int)> dp = [&](int x, int y1, int y2) {
      if (x == m) return 0;
      if (y1 < 0 || y1 == n || y2 < 0 || y2 == n) return 0;
      int& ans = memo[x][y1][y2];
      if (ans != -1) return ans;

      const int currRow = grid[x][y1] + (y1 != y2) * grid[x][y2];

      for (int d1 = -1; d1 <= 1; ++d1)
        for (int d2 = -1; d2 <= 1; ++d2)
          ans = max(ans, currRow + dp(x + 1, y1 + d1, y2 + d2));

      return ans;
    };

    return dp(0, 0, n - 1);
  }
};