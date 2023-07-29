class Solution {
 public:
  vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
    const int m = isWater.size();
    const int n = isWater[0].size();
    const vector<int> dirs{0, 1, 0, -1, 0};
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
      for (int k = 0; k < 4; ++k) {
        const int x = i + dirs[k];
        const int y = j + dirs[k + 1];
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
