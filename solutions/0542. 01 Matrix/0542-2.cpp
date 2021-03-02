class Solution {
 public:
  vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
    const int m = matrix.size();
    const int n = matrix[0].size();
    const vector<int> dirs{0, 1, 0, -1, 0};

    queue<pair<int, int>> q;

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (matrix[i][j] == 0)
          q.push({i, j});
        else
          matrix[i][j] = INT_MAX;

    while (!q.empty()) {
      const auto [i, j] = q.front();
      q.pop();
      for (int k = 0; k < 4; ++k) {
        const int x = i + dirs[k];
        const int y = j + dirs[k + 1];
        if (x < 0 || x == m || y < 0 || y == n)
          continue;
        if (matrix[x][y] <= matrix[i][j] + 1)
          continue;
        q.push({x, y});
        matrix[x][y] = matrix[i][j] + 1;
      }
    }

    return matrix;
  }
};
