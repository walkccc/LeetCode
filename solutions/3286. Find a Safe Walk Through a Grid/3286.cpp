class Solution {
 public:
  bool findSafeWalk(vector<vector<int>>& grid, int health) {
    constexpr int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    const int m = grid.size();
    const int n = grid[0].size();
    const int initialHealth = health - grid[0][0];
    using T = tuple<int, int, int>;  // (i, j, h)
    queue<T> q{{{0, 0, initialHealth}}};
    vector<vector<vector<bool>>> seen(
        m, vector<vector<bool>>(n, vector<bool>(health + 1)));
    seen[0][0][initialHealth] = true;

    while (!q.empty())
      for (int sz = q.size(); sz > 0; --sz) {
        const auto [i, j, h] = q.front();
        q.pop();
        if (i == m - 1 && j == n - 1 && h > 0)
          return true;
        for (const auto& [dx, dy] : dirs) {
          const int x = i + dx;
          const int y = j + dy;
          if (x < 0 || x == m || y < 0 || y == n)
            continue;
          const int nextHealth = h - grid[x][y];
          if (nextHealth <= 0 || seen[x][y][nextHealth])
            continue;
          q.emplace(x, y, nextHealth);
          seen[x][y][nextHealth] = true;
        }
      }

    return false;
  }
};
