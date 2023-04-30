class Solution {
 public:
  void wallsAndGates(vector<vector<int>>& rooms) {
    const int m = rooms.size();
    const int n = rooms[0].size();
    const vector<int> dirs{0, 1, 0, -1, 0};
    queue<pair<int, int>> q;

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (rooms[i][j] == 0)
          q.emplace(i, j);

    while (!q.empty()) {
      const auto [i, j] = q.front();
      q.pop();
      for (int k = 0; k < 4; ++k) {
        const int x = i + dirs[k];
        const int y = j + dirs[k + 1];
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
