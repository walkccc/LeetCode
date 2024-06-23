class Solution {
 public:
  int countPaths(vector<vector<int>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();
    int ans = 0;
    vector<vector<int>> mem(m, vector<int>(n, -1));

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        ans += countPaths(grid, i, j, mem);
        ans %= kMod;
      }

    return ans;
  }

 private:
  static constexpr int kMod = 1'000'000'007;
  static constexpr int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

  // Returns the number of increasing paths starting from (i, j).
  int countPaths(const vector<vector<int>>& grid, int i, int j,
                 vector<vector<int>>& mem) {
    if (mem[i][j] != -1)
      return mem[i][j];

    mem[i][j] = 1;  // The current cell contributes 1 length.

    for (const auto& [dx, dy] : dirs) {
      const int x = i + dx;
      const int y = j + dy;
      if (x < 0 || x == grid.size() || y < 0 || y == grid[0].size())
        continue;
      if (grid[x][y] <= grid[i][j])
        continue;
      mem[i][j] += countPaths(grid, x, y, mem);
      mem[i][j] %= kMod;
    }

    return mem[i][j];
  }
};
