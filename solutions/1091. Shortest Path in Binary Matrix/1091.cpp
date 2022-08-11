class Solution {
 public:
  int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    const int n = grid.size();
    if (grid[0][0] == 0 && n == 1)
      return 1;
    if (grid[0][0] == 1 || grid.back().back() == 1)
      return -1;

    const vector<pair<int, int>> dirs{{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                                      {0, 1},   {1, -1}, {1, 0},  {1, 1}};

    int ans = 0;
    queue<pair<int, int>> q{{{0, 0}}};
    vector<vector<bool>> seen(n, vector<bool>(n));
    seen[0][0] = true;

    while (!q.empty()) {
      ++ans;
      for (int sz = q.size(); sz > 0; --sz) {
        const auto [i, j] = q.front();
        q.pop();
        for (const auto [dx, dy] : dirs) {
          const int x = i + dx;
          const int y = j + dy;
          if (x < 0 || x == n || y < 0 || y == n)
            continue;
          if (grid[x][y] != 0 || seen[x][y])
            continue;
          if (x == n - 1 && y == n - 1)
            return ans + 1;
          q.emplace(x, y);
          seen[x][y] = true;
        }
      }
    }

    return -1;
  }
};
