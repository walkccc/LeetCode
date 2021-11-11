class Solution {
 public:
  vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
    const int m = A.size();
    const int n = B.size();
    const int l = B[0].size();

    vector<vector<int>> ans(m, vector<int>(l));

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < l; ++j)
        for (int k = 0; k < n; ++k)
          ans[i][j] += A[i][k] * B[k][j];

    return ans;
  }
};
