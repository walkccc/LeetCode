class Solution {
 public:
  int shortestDistance(vector<vector<int>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();
    const int buildingCount = getBuildingCount(grid);
    const vector<int> dirs{0, 1, 0, -1, 0};

    int ans = INT_MAX;
    // dist[i][j] := total distance of grid[i][j] (0) to reach all buildings (1)
    vector<vector<int>> dist(m, vector<int>(n));
    // reachCount[i][j] := # of building grid[i][j] (0) can reach
    vector<vector<int>> reachCount(m, vector<int>(n));

    auto bfs = [&](int row, int col) {
      queue<pair<int, int>> q{{{row, col}}};
      vector<vector<bool>> seen(m, vector<bool>(n));
      int level = 0;

      while (!q.empty()) {
        ++level;
        for (int size = q.size(); size > 0; --size) {
          const auto [i, j] = q.front(); q.pop();
          for (int k = 0; k < 4; ++k) {
            const int x = i + dirs[k];
            const int y = j + dirs[k + 1];
            if (x < 0 || x == m || y < 0 || y == n) continue;
            if (grid[x][y] != 0 || seen[x][y]) continue;
            dist[x][y] += level;
            ++reachCount[x][y];
            q.push({x, y});
            seen[x][y] = true;
          }
        }
      }
    };

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (grid[i][j] == 1)  // bfs from this building
          bfs(i, j);

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (reachCount[i][j] == buildingCount)
          ans = min(ans, dist[i][j]);

    return ans == INT_MAX ? -1 : ans;
  }

 private:
  int getBuildingCount(const vector<vector<int>>& grid) {
    int buildingCount = 0;
    for (const vector<int>& row : grid)
      buildingCount +=
          count_if(begin(row), end(row), [](int cell) { return cell == 1; });
    return buildingCount;
  }
};