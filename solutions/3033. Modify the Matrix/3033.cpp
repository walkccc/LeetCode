class Solution {
 public:
  vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
    const int m = matrix.size();
    const int n = matrix[0].size();
    vector<vector<int>> ans = matrix;

    for (int j = 0; j < n; ++j) {
      int mx = 0;
      for (int i = 0; i < m; ++i)
        mx = max(mx, matrix[i][j]);
      for (int i = 0; i < m; ++i)
        if (matrix[i][j] == -1)
          ans[i][j] = mx;
    }

    return ans;
  }
};
