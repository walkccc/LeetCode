class Solution {
 public:
  int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    const int n = grid.size();
    if (grid[0][0] == 0 && n == 1)
      return 1;
    if (grid[0][0] == 1 || grid.back().back() == 1)
      return -1;

    constexpr int kDirs[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                                 {0, 1},   {1, -1}, {1, 0},  {1, 1}};
    queue<pair<int, int>> q{{{0, 0}}};
    vector<vector<bool>> seen(n, vector<bool>(n));
    seen[0][0] = true;

    for (int step = 1; !q.empty(); ++step)
      for (int sz = q.size(); sz > 0; --sz) {
        const auto [i, j] = q.front();
        q.pop();
        for (const auto& [dx, dy] : kDirs) {
          const int x = i + dx;
          const int y = j + dy;
          if (x < 0 || x == n || y < 0 || y == n)
            continue;
          if (grid[x][y] != 0 || seen[x][y])
            continue;
          if (x == n - 1 && y == n - 1)
            return step + 1;
          q.emplace(x, y);
          seen[x][y] = true;
        }
      }

    return -1;
  }
};
