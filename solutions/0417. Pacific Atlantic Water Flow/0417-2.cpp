class Solution {
 public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
    if (matrix.empty())
      return {};

    const int m = matrix.size();
    const int n = matrix[0].size();

    vector<vector<int>> ans;
    vector<vector<bool>> seenP(m, vector<bool>(n));
    vector<vector<bool>> seenA(m, vector<bool>(n));

    for (int i = 0; i < m; ++i) {
      dfs(matrix, i, 0, seenP);
      dfs(matrix, i, n - 1, seenA);
    }

    for (int j = 0; j < n; ++j) {
      dfs(matrix, 0, j, seenP);
      dfs(matrix, m - 1, j, seenA);
    }

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (seenP[i][j] && seenA[i][j])
          ans.push_back({i, j});

    return ans;
  }

 private:
  void dfs(const vector<vector<int>>& matrix, int i, int j,
           vector<vector<bool>>& seen, int h = 0) {
    if (i < 0 || i == matrix.size() || j < 0 || j == matrix[0].size())
      return;
    if (seen[i][j] || matrix[i][j] < h)
      return;

    seen[i][j] = true;
    dfs(matrix, i + 1, j, seen, matrix[i][j]);
    dfs(matrix, i - 1, j, seen, matrix[i][j]);
    dfs(matrix, i, j + 1, seen, matrix[i][j]);
    dfs(matrix, i, j - 1, seen, matrix[i][j]);
  }
};
