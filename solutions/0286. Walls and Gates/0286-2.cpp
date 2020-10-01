class Solution {
 public:
  void wallsAndGates(vector<vector<int>>& rooms) {
    if (rooms.empty()) return;

    const int m = rooms.size();
    const int n = rooms[0].size();

    function<void(int, int, int)> dfs = [&](int i, int j, int distance) {
      if (i < 0 || i == m || j < 0 || j == n) return;
      if (rooms[i][j] < distance) return;

      rooms[i][j] = distance;
      dfs(i + 1, j, distance + 1);
      dfs(i - 1, j, distance + 1);
      dfs(i, j + 1, distance + 1);
      dfs(i, j - 1, distance + 1);
    };

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (rooms[i][j] == 0)
          dfs(i, j, 0);
  }
};