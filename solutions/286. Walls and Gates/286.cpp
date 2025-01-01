class Solution {
 public:
  void wallsAndGates(vector<vector<int>>& rooms) {
    constexpr int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    const int m = rooms.size();
    const int n = rooms[0].size();
    queue<pair<int, int>> q;

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (rooms[i][j] == 0)
          q.emplace(i, j);

    while (!q.empty()) {
      const auto [i, j] = q.front();
      q.pop();
      for (const auto& [dx, dy] : dirs) {
        const int x = i + dx;
        const int y = j + dy;
        if (x < 0 || x == m || y < 0 || y == n)
          continue;
        if (rooms[x][y] != INT_MAX)
          continue;
        rooms[x][y] = rooms[i][j] + 1;
        q.emplace(x, y);
      }
    }
  }
};
