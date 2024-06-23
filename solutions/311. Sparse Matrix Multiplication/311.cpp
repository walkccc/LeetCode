class Solution {
 public:
  vector<vector<int>> multiply(vector<vector<int>>& mat1,
                               vector<vector<int>>& mat2) {
    const int m = mat1.size();
    const int n = mat2.size();
    const int l = mat2[0].size();
    vector<vector<int>> ans(m, vector<int>(l));

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < l; ++j)
        for (int k = 0; k < n; ++k)
          ans[i][j] += mat1[i][k] * mat2[k][j];

    return ans;
  }
};
