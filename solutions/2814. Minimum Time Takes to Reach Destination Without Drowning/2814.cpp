class Solution {
 public:
  int minimumSeconds(vector<vector<string>>& land) {
    const int m = land.size();
    const int n = land[0].size();
    const vector<vector<int>> floodDist = getFloodDist(land);
    queue<pair<int, int>> q;
    vector<vector<bool>> seen(m, vector<bool>(n));

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (land[i][j] == "S") {
          q.emplace(i, j);
          seen[i][j] = true;
        }

    for (int step = 1; !q.empty(); ++step)
      for (int sz = q.size(); sz > 0; --sz) {
        const auto [i, j] = q.front();
        q.pop();
        for (const auto& [dx, dy] : dirs) {
          const int x = i + dx;
          const int y = j + dy;
          if (x < 0 || x == m || y < 0 || y == n)
            continue;
          if (land[x][y] == "D")
            return step;
          if (floodDist[x][y] <= step || land[x][y] == "X" || seen[x][y])
            continue;
          q.emplace(x, y);
          seen[x][y] = true;
        }
      }

    return -1;
  }

 private:
  static constexpr int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

  vector<vector<int>> getFloodDist(const vector<vector<string>>& land) {
    const int m = land.size();
    const int n = land[0].size();
    vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
    queue<pair<int, int>> q;
    vector<vector<bool>> seen(m, vector<bool>(n));

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (land[i][j] == "*") {
          q.emplace(i, j);
          seen[i][j] = true;
        }

    for (int d = 0; !q.empty(); ++d)
      for (int sz = q.size(); sz > 0; --sz) {
        const auto [i, j] = q.front();
        q.pop();
        dist[i][j] = d;
        for (const auto& [dx, dy] : dirs) {
          const int x = i + dx;
          const int y = j + dy;
          if (x < 0 || x == m || y < 0 || y == n)
            continue;
          if (land[x][y] == "X" || land[x][y] == "D" || seen[x][y])
            continue;
          q.emplace(x, y);
          seen[x][y] = true;
        }
      }

    return dist;
  }
};
