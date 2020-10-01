class Solution {
 public:
  vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
    const int m = matrix.size();
    const int n = matrix[0].size();
    const vector<int> dirs{0, 1, 0, -1, 0};

    vector<vector<bool>> seen(m, vector<bool>(n, false));
    queue<pair<int, int>> queue;

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (matrix[i][j] == 0) {
          queue.push({i, j});
          seen[i][j] = true;
        }

    while (!queue.empty()) {
      const auto [i, j] = queue.front(); queue.pop();
      for (int k = 0; k < 4; ++k) {
        const int x = i + dirs[k];
        const int y = j + dirs[k + 1];
        if (x < 0 || x == m || y < 0 || y == n) continue;
        if (seen[x][y]) continue;
        matrix[x][y] = matrix[i][j] + 1;
        queue.push({x, y});
        seen[x][y] = true;
      }
    }

    return matrix;
  }
};