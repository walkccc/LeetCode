class Solution {
 public:
  int shortestDistance(vector<vector<int>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();
    const int nBuildings = getBuildingCount(grid);
    const vector<int> dirs{0, 1, 0, -1, 0};
    int ans = INT_MAX;
    // dist[i][j] := total distance of grid[i][j] (0) to reach all buildings (1)
    vector<vector<int>> dist(m, vector<int>(n));
    // reachCount[i][j] := # of buildings (1) grid[i][j] (0) can reach
    vector<vector<int>> reachCount(m, vector<int>(n));

    auto bfs = [&](int row, int col) -> bool {
      queue<pair<int, int>> q{{{row, col}}};
      vector<vector<bool>> seen(m, vector<bool>(n));
      seen[row][col] = true;
      int depth = 0;
      int seenBuildings = 1;

      while (!q.empty()) {
        ++depth;
        for (int sz = q.size(); sz > 0; --sz) {
          const auto [i, j] = q.front();
          q.pop();
          for (int k = 0; k < 4; ++k) {
            const int x = i + dirs[k];
            const int y = j + dirs[k + 1];
            if (x < 0 || x == m || y < 0 || y == n)
              continue;
            if (seen[x][y])
              continue;
            seen[x][y] = true;
            if (!grid[x][y]) {
              dist[x][y] += depth;
              ++reachCount[x][y];
              q.emplace(x, y);
            } else if (grid[x][y] == 1) {
              ++seenBuildings;
            }
          }
        }
      }

      return seenBuildings == nBuildings;
    };

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (grid[i][j] == 1)  // bfs from this building
          if (!bfs(i, j))
            return -1;

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (reachCount[i][j] == nBuildings)
          ans = min(ans, dist[i][j]);

    return ans == INT_MAX ? -1 : ans;
  }

 private:
  int getBuildingCount(vector<vector<int>>& grid) {
    return accumulate(begin(grid), end(grid), 0, [](int s, vector<int>& row) {
      return s + count(begin(row), end(row), 1);
    });
  }
};
