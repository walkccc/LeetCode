class Solution {
 public:
  vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
    const int m = mat.size();
    const int n = mat[0].size();
    vector<vector<int>> ans(m, vector<int>(n));
    vector<vector<int>> prefix(m + 1, vector<int>(n + 1));

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        prefix[i + 1][j + 1] =
            mat[i][j] + prefix[i][j + 1] + prefix[i + 1][j] - prefix[i][j];

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        const int r1 = max(0, i - k) + 1;
        const int c1 = max(0, j - k) + 1;
        const int r2 = min(m - 1, i + k) + 1;
        const int c2 = min(n - 1, j + k) + 1;
        ans[i][j] = prefix[r2][c2] - prefix[r2][c1 - 1] - prefix[r1 - 1][c2] +
                    prefix[r1 - 1][c1 - 1];
      }

    return ans;
  }
};
