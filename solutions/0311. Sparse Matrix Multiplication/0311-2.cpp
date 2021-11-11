class Solution {
 public:
  vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
    const int m = A.size();
    const int n = B.size();
    const int l = B[0].size();

    vector<vector<int>> ans(m, vector<int>(l));
    vector<vector<int>> nonZeroColIndicesInB;

    for (int i = 0; i < n; ++i) {
      vector<int> colIndices;
      for (int j = 0; j < l; ++j)
        if (B[i][j] != 0)
          colIndices.push_back(j);
      nonZeroColIndicesInB.push_back(colIndices);
    }

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        if (A[i][j] == 0)
          continue;
        // A's j-th column matches B's j-th row
        for (const int colIndex : nonZeroColIndicesInB[j])
          ans[i][colIndex] += A[i][j] * B[j][colIndex];
      }

    return ans;
  }
};
