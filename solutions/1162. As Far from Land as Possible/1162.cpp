class Solution {
 public:
  int maxDistance(vector<vector<int>>& grid) {
    constexpr int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    const int m = grid.size();
    const int n = grid[0].size();
    queue<pair<int, int>> q;
    int water = 0;

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (grid[i][j] == 0)
          ++water;
        else
          q.emplace(i, j);

    if (water == 0 || water == m * n)
      return -1;

    int ans = 0;

    for (int d = 0; !q.empty(); ++d)
      for (int sz = q.size(); sz > 0; --sz) {
        const auto [i, j] = q.front();
        q.pop();
        ans = d;
        for (const auto& [dx, dy] : dirs) {
          const int x = i + dx;
          const int y = j + dy;
          if (x < 0 || x == m || y < 0 || y == n)
            continue;
          if (grid[x][y] > 0)
            continue;
          q.emplace(x, y);
          grid[x][y] = 2;  // Mark as visited.
        }
      }

    return ans;
  }
};
