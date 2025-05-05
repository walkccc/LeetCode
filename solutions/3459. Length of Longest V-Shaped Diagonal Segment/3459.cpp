class Solution {
 public:
  int lenOfVDiagonal(vector<vector<int>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();
    vector<vector<vector<vector<vector<int>>>>> mem(
        m, vector<vector<vector<vector<int>>>>(
               n, vector<vector<vector<int>>>(
                      2, vector<vector<int>>(2, vector<int>(4, -1)))));
    int res = 0;

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (grid[i][j] == 1)
          for (int d = 0; d < 4; ++d) {
            const auto& [dx, dy] = kDirs[d];
            res = max(res, 1 + dfs(grid, i + dx, j + dy, /*turned=*/false, 2, d,
                                   mem));
          }

    return res;
  }

 private:
  static constexpr int kDirs[4][2] = {{-1, 1}, {1, 1}, {1, -1}, {-1, -1}};

  int dfs(const vector<vector<int>>& grid, int i, int j, bool turned, int num,
          int dir, vector<vector<vector<vector<vector<int>>>>>& mem) {
    if (i < 0 || i == grid.size() || j < 0 || j == grid[0].size())
      return 0;
    if (grid[i][j] != num)
      return 0;

    const int hashNum = max(0, num - 1);
    if (mem[i][j][turned][hashNum][dir] != -1)
      return mem[i][j][turned][hashNum][dir];

    const int nextNum = num == 2 ? 0 : 2;
    const auto& [dx, dy] = kDirs[dir];
    int res = 1 + dfs(grid, i + dx, j + dy, turned, nextNum, dir, mem);

    if (!turned) {
      const int nextDir = (dir + 1) % 4;
      const auto& [nextDx, nextDy] = kDirs[nextDir];
      res = max(res, 1 + dfs(grid, i + nextDx, j + nextDy, /*turned=*/true,
                             nextNum, nextDir, mem));
    }

    return mem[i][j][turned][hashNum][dir] = res;
  }
};
