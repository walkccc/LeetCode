class Solution {
 public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
    if (matrix.empty())
      return {};

    const int m = matrix.size();
    const int n = matrix[0].size();
    const vector<int> dirs{0, 1, 0, -1, 0};

    vector<vector<int>> ans;
    queue<pair<int, int>> qP;
    queue<pair<int, int>> qA;
    vector<vector<bool>> seenP(m, vector<bool>(n));
    vector<vector<bool>> seenA(m, vector<bool>(n));

    auto bfs = [&](queue<pair<int, int>>& q, vector<vector<bool>>& seen) {
      while (!q.empty()) {
        const auto [i, j] = q.front();
        q.pop();
        const int h = matrix[i][j];
        for (int k = 0; k < 4; ++k) {
          const int x = i + dirs[k];
          const int y = j + dirs[k + 1];
          if (x < 0 || x == m || y < 0 || y == n)
            continue;
          if (seen[x][y] || matrix[x][y] < h)
            continue;
          q.push({x, y});
          seen[x][y] = true;
        }
      }
    };

    for (int i = 0; i < m; ++i) {
      qP.push({i, 0});
      qA.push({i, n - 1});
      seenP[i][0] = true;
      seenA[i][n - 1] = true;
    }

    for (int j = 0; j < n; ++j) {
      qP.push({0, j});
      qA.push({m - 1, j});
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
