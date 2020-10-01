class Solution {
 public:
  int cutOffTree(vector<vector<int>>& forest) {
    const int m = forest.size();
    const int n = forest[0].size();
    const vector<int> dirs{0, 1, 0, -1, 0};

    auto compare = [&](const pair<int, int>& a, const pair<int, int>& b) {
      return forest[a.first][a.second] >
             forest[b.first][b.second];  // sorted by tree's height
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)>
        pq(compare);

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (forest[i][j] > 0)
          pq.push({i, j});

    auto bfs = [&](int si, int sj, int ei, int ej) {
      int steps = 0;
      queue<pair<int, int>> q{{{si, sj}}};
      vector<vector<bool>> seen(m, vector<bool>(n));
      seen[si][sj] = true;

      while (!q.empty()) {
        for (int s = q.size(); s > 0; --s) {
          const auto [i, j] = q.front(); q.pop();
          if (i == ei && j == ej) return steps;
          for (int k = 0; k < 4; ++k) {
            const int x = i + dirs[k];
            const int y = j + dirs[k + 1];
            if (x < 0 || x == m || y < 0 || y == n) continue;
            if (seen[x][y] || forest[x][y] == 0) continue;
            q.push({x, y});
            seen[x][y] = true;
          }
        }
        ++steps;
      }

      return -1;
    };

    int ans = 0;
    int i = 0;
    int j = 0;

    while (!pq.empty()) {
      const auto [row, col] = pq.top(); pq.pop();
      // walk from (i, j) to (row, col)
      const int steps = bfs(i, j, row, col);
      if (steps < 0) return -1;
      ans += steps;
      i = row;
      j = col;
    }

    return ans;
  }
};