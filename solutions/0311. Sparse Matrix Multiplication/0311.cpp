class Solution {
 public:
  vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
    const int l = A.size();
    const int m = B.size();
    const int n = B[0].size();

    vector<vector<int>> ans(l, vector<int>(n));

    for (int i = 0; i < l; ++i)
      for (int j = 0; j < n; ++j)
        for (int k = 0; k < m; ++k)
          ans[i][j] += A[i][k] * B[k][j];

    return ans;
  }
};
