class Solution {
 public:
  int shortestPath(vector<vector<int>>& grid, int k) {
    const int m = grid.size();
    const int n = grid[0].size();
    if (m == 1 && n == 1)
      return 0;

    constexpr int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    queue<tuple<int, int, int>> q{{{0, 0, k}}};  // (i, j, eliminate)
    vector<vector<vector<bool>>> seen(
        m, vector<vector<bool>>(n, vector<bool>(k + 1)));
    seen[0][0][k] = true;

    for (int step = 1; !q.empty(); ++step)
      for (int sz = q.size(); sz > 0; --sz) {
        const auto [i, j, eliminate] = q.front();
        q.pop();
        for (const auto& [dx, dy] : dirs) {
          const int x = i + dx;
          const int y = j + dy;
          if (x < 0 || x == m || y < 0 || y == n)
            continue;
          if (x == m - 1 && y == n - 1)
            return step;
          if (grid[x][y] == 1 && eliminate == 0)
            continue;
          const int newEliminate = eliminate - grid[x][y];
          if (seen[x][y][newEliminate])
            continue;
          q.emplace(x, y, newEliminate);
          seen[x][y][newEliminate] = true;
        }
      }

    return -1;
  }
};
