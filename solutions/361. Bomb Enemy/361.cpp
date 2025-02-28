class Solution {
 public:
  int maxKilledEnemies(vector<vector<char>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();
    int enemyCount = 0;
    // dp[i][j] := the maximum enemies grid[i][j] can kill
    vector<vector<int>> dp(m, vector<int>(n));

    auto update = [&](int i, int j) {
      if (grid[i][j] == '0')
        dp[i][j] += enemyCount;
      else if (grid[i][j] == 'E')
        ++enemyCount;
      else  // grid[i][j] == 'W'
        enemyCount = 0;
    };

    // Extend the four directions, if meet 'W', need to start over from 0.
    for (int i = 0; i < m; ++i) {
      enemyCount = 0;
      for (int j = 0; j < n; ++j)
        update(i, j);
      enemyCount = 0;
      for (int j = n - 1; j >= 0; --j)
        update(i, j);
    }

    for (int j = 0; j < n; ++j) {
      enemyCount = 0;
      for (int i = 0; i < m; ++i)
        update(i, j);
      enemyCount = 0;
      for (int i = m - 1; i >= 0; --i)
        update(i, j);
    }

    return accumulate(dp.begin(), dp.end(), 0,
                      [](int subtotal, const vector<int>& row) {
      return max(subtotal, ranges::max(row));
    });
  }
};
