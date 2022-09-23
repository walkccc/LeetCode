class Solution {
 public:
  int shortestBridge(vector<vector<int>>& grid) {
    const int n = grid.size();
    const vector<int> dirs{0, 1, 0, -1, 0};
    int ans = 0;
    queue<pair<int, int>> q;

    markGridTwo(grid, q);

    // expand by BFS
    while (!q.empty()) {
      for (int sz = q.size(); sz > 0; --sz) {
        const auto [i, j] = q.front();
        q.pop();
        for (int k = 0; k < 4; ++k) {
          const int x = i + dirs[k];
          const int y = j + dirs[k + 1];
          if (x < 0 || x == n || y < 0 || y == n)
            continue;
          if (grid[x][y] == 2)
            continue;
          if (grid[x][y] == 1)
            return ans;
          grid[x][y] = 2;
          q.emplace(x, y);
        }
      }
      ++ans;
    }

    throw;
  }

 private:
  // mark one group to 2s by DFS
  void markGridTwo(vector<vector<int>>& grid, queue<pair<int, int>>& q) {
    for (int i = 0; i < grid.size(); ++i)
      for (int j = 0; j < grid[0].size(); ++j)
        if (grid[i][j] == 1) {
          markGridTwo(grid, i, j, q);
          return;
        }
  }

  // mark one group to 2s by DFS and push them to the q
  void markGridTwo(vector<vector<int>>& grid, int i, int j,
                   queue<pair<int, int>>& q) {
    if (i < 0 || i == grid.size() || j < 0 || j == grid[0].size())
      return;
    if (grid[i][j] != 1)
      return;

    grid[i][j] = 2;
    q.emplace(i, j);
    markGridTwo(grid, i + 1, j, q);
    markGridTwo(grid, i - 1, j, q);
    markGridTwo(grid, i, j + 1, q);
    markGridTwo(grid, i, j - 1, q);
  }
};
