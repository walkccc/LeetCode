class Solution {
 public:
  vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
    constexpr int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    const int m = isWater.size();
    const int n = isWater[0].size();
    vector<vector<int>> ans(m, vector<int>(n, -1));
    queue<pair<int, int>> q;

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (isWater[i][j] == 1) {
          q.emplace(i, j);
          ans[i][j] = 0;
        }

    while (!q.empty()) {
      const auto [i, j] = q.front();
      q.pop();
      for (const auto& [dx, dy] : dirs) {
        const int x = i + dx;
        const int y = j + dy;
        if (x < 0 || x == m || y < 0 || y == n)
          continue;
        if (ans[x][y] != -1)
          continue;
        ans[x][y] = ans[i][j] + 1;
        q.emplace(x, y);
      }
    }

    return ans;
  }
};
