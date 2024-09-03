class Solution {
 public:
  int shortestBridge(vector<vector<int>>& grid) {
    constexpr int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    const int n = grid.size();
    queue<pair<int, int>> q;

    markGridTwo(grid, q);

    for (int ans = 0; !q.empty(); ++ans)
      for (int sz = q.size(); sz > 0; --sz) {
        const auto [i, j] = q.front();
        q.pop();
        for (const auto& [dx, dy] : dirs) {
          const int x = i + dx;
          const int y = j + dy;
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

    throw;
  }

 private:
  // Marks one group to 2s by DFS.
  void markGridTwo(vector<vector<int>>& grid, queue<pair<int, int>>& q) {
    for (int i = 0; i < grid.size(); ++i)
      for (int j = 0; j < grid[0].size(); ++j)
        if (grid[i][j] == 1) {
          markGridTwo(grid, i, j, q);
          return;
        }
  }

  // Marks one group to 2s by DFS and pushes them to the queue.
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
