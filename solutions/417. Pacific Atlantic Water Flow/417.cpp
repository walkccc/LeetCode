class Solution {
 public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    constexpr int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    const int m = heights.size();
    const int n = heights[0].size();
    vector<vector<int>> ans;
    queue<pair<int, int>> qP;
    queue<pair<int, int>> qA;
    vector<vector<bool>> seenP(m, vector<bool>(n));
    vector<vector<bool>> seenA(m, vector<bool>(n));

    auto bfs = [&](queue<pair<int, int>>& q, vector<vector<bool>>& seen) {
      while (!q.empty()) {
        const auto [i, j] = q.front();
        q.pop();
        const int h = heights[i][j];
        for (const auto& [dx, dy] : dirs) {
          const int x = i + dx;
          const int y = j + dy;
          if (x < 0 || x == m || y < 0 || y == n)
            continue;
          if (seen[x][y] || heights[x][y] < h)
            continue;
          q.emplace(x, y);
          seen[x][y] = true;
        }
      }
    };

    for (int i = 0; i < m; ++i) {
      qP.emplace(i, 0);
      qA.emplace(i, n - 1);
      seenP[i][0] = true;
      seenA[i][n - 1] = true;
    }

    for (int j = 0; j < n; ++j) {
      qP.emplace(0, j);
      qA.emplace(m - 1, j);
      seenP[0][j] = true;
      seenA[m - 1][j] = true;
    }

    bfs(qP, seenP);
    bfs(qA, seenA);

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (seenP[i][j] && seenA[i][j])
          ans.push_back({i, j});

    return ans;
  }
};
