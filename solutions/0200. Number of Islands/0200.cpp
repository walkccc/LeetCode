class Solution {
 public:
  int numIslands(vector<vector<char>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();
    const vector<int> dirs{0, 1, 0, -1, 0};
    int ans = 0;

    auto bfs = [&](int r, int c) {
      queue<pair<int, int>> q{{{r, c}}};
      grid[r][c] = '2';  // mark '2' as visited
      while (!q.empty()) {
        const auto [i, j] = q.front();
        q.pop();
        for (int k = 0; k < 4; ++k) {
          const int x = i + dirs[k];
          const int y = j + dirs[k + 1];
          if (x < 0 || x == m || y < 0 || y == n)
            continue;
          if (grid[x][y] != '1')
            continue;
          q.emplace(x, y);
          grid[x][y] = '2';  // mark '2' as visited
        }
      }
    };

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (grid[i][j] == '1') {
          bfs(i, j);
          ++ans;
        }

    return ans;
  }
};
