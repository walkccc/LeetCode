class Solution {
 public:
  vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    const int m = mat.size();
    const int n = mat[0].size();
    const vector<int> dirs{0, 1, 0, -1, 0};
    queue<pair<int, int>> q;
    vector<vector<bool>> seen(m, vector<bool>(n));

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (mat[i][j] == 0) {
          q.emplace(i, j);
          seen[i][j] = true;
        }

    while (!q.empty()) {
      const auto [i, j] = q.front();
      q.pop();
      for (int k = 0; k < 4; ++k) {
        const int x = i + dirs[k];
        const int y = j + dirs[k + 1];
        if (x < 0 || x == m || y < 0 || y == n)
          continue;
        if (seen[x][y])
          continue;
        mat[x][y] = mat[i][j] + 1;
        q.emplace(x, y);
        seen[x][y] = true;
      }
    }

    return mat;
  }
};
