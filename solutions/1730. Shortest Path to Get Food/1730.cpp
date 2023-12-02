class Solution {
 public:
  int getFood(vector<vector<char>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();
    const vector<int> dirs{0, 1, 0, -1, 0};
    queue<pair<int, int>> q{{getStartLocation(grid)}};

    for (int ans = 0; !q.empty(); ++ans)
      for (int sz = q.size(); sz > 0; --sz) {
        const auto [i, j] = q.front();
        q.pop();
        for (int k = 0; k < 4; ++k) {
          const int x = i + dirs[k];
          const int y = j + dirs[k + 1];
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
