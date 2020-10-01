class Solution {
 public:
  vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
    const int l = A.size();
    const int m = B.size();
    const int n = B[0].size();

    vector<vector<int>> ans(l, vector<int>(n));
    vector<vector<int>> nonZeroColIndicesInB;

    for (int i = 0; i < m; ++i) {
      vector<int> colIndices;
      for (int j = 0; j < n; ++j)
        if (B[i][j] != 0)
          colIndices.push_back(j);
      nonZeroColIndicesInB.push_back(colIndices);
    }

    for (int i = 0; i < l; ++i)
      for (int j = 0; j < m; ++j) {
        if (A[i][j] == 0) continue;
        for (const int colIndex : nonZeroColIndicesInB[j])
          ans[i][colIndex] += A[i][j] * B[j][colIndex];
      }

    return ans;
  }
};
