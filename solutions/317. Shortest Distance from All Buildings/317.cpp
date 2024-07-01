class Solution {
 public:
  int shortestDistance(vector<vector<int>>& grid) {
    constexpr int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    const int m = grid.size();
    const int n = grid[0].size();
    const int nBuildings = getBuildingsCount(grid);
    int ans = INT_MAX;
    // dist[i][j] := the total distance of grid[i][j] (0) to reach all the
    // buildings (1)
    vector<vector<int>> dist(m, vector<int>(n));
    // reachCount[i][j] := the number of buildings (1) grid[i][j] (0) can reach
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
          for (const auto& [dx, dy] : dirs) {
            const int x = i + dx;
            const int y = j + dy;
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
        if (grid[i][j] == 1)  // BFS from this building.
          if (!bfs(i, j))
            return -1;

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (reachCount[i][j] == nBuildings)
          ans = min(ans, dist[i][j]);

    return ans == INT_MAX ? -1 : ans;
  }

 private:
  int getBuildingsCount(vector<vector<int>>& grid) {
    return accumulate(grid.begin(), grid.end(), 0,
                      [](int subtotal, vector<int>& row) {
      return subtotal + ranges::count(row, 1);
    });
  }
};
