class Solution {
 public:
  int getFood(vector<vector<char>>& grid) {
    constexpr int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    const int m = grid.size();
    const int n = grid[0].size();
    queue<pair<int, int>> q{{getStartLocation(grid)}};

    for (int ans = 0; !q.empty(); ++ans)
      for (int sz = q.size(); sz > 0; --sz) {
        const auto [i, j] = q.front();
        q.pop();
        for (const auto& [dx, dy] : dirs) {
          const int x = i + dx;
          const int y = j + dy;
          if (x < 0 || x == m || y < 0 || y == n)
            continue;
          if (grid[x][y] == 'X')
            continue;
          if (grid[x][y] == '#')
            return ans + 1;
          q.emplace(x, y);
          grid[x][y] = 'X';  // Mark as visited.
        }
      }

    return -1;
  }

 private:
  pair<int, int> getStartLocation(const vector<vector<char>>& grid) {
    for (int i = 0; i < grid.size(); ++i)
      for (int j = 0; j < grid[0].size(); ++j)
        if (grid[i][j] == '*')
          return {i, j};
    throw;
  }
};
