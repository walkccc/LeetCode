class Solution {
 public:
  int minimumOperations(vector<vector<int>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();
    int ans = 0;
    vector<vector<int>> seen(m, vector<int>(n));
    vector<vector<int>> match(m, vector<int>(n, -1));

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (grid[i][j] == 1 && match[i][j] == -1) {
          const int sessionId = i * n + j;
          seen[i][j] = sessionId;
          ans += dfs(grid, i, j, sessionId, seen, match);
        }

    return ans;
  }

 private:
  const vector<int> dirs{0, 1, 0, -1, 0};

  int dfs(const vector<vector<int>>& grid, int i, int j, int sessionId,
          vector<vector<int>>& seen, vector<vector<int>>& match) {
    const int m = grid.size();
    const int n = grid[0].size();

    for (int k = 0; k < 4; ++k) {
      const int x = i + dirs[k];
      const int y = j + dirs[k + 1];
      if (x < 0 || x == m || y < 0 || y == n)
        continue;
      if (grid[x][y] == 0 || seen[x][y] == sessionId)
        continue;
      seen[x][y] = sessionId;
      if (match[x][y] == -1 ||
          dfs(grid, match[x][y] / n, match[x][y] % n, sessionId, seen, match)) {
        match[x][y] = i * n + j;
        match[i][j] = x * n + y;
        return 1;
      }
    }

    return 0;
  }
};
