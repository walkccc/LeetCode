class Solution {
 public:
  vector<vector<int>> multiply(vector<vector<int>>& mat1,
                               vector<vector<int>>& mat2) {
    const int m = mat1.size();
    const int n = mat2.size();
    const int l = mat2[0].size();
    vector<vector<int>> ans(m, vector<int>(l));
    vector<vector<int>> nonZeroColIndicesInMat2;

    for (int i = 0; i < n; ++i) {
      vector<int> colIndices;
      for (int j = 0; j < l; ++j)
        if (mat2[i][j] != 0)
          colIndices.push_back(j);
      nonZeroColIndicesInMat2.push_back(colIndices);
    }

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        if (mat1[i][j] == 0)
          continue;
        // mat1's j-th column matches mat2's j-th row
        for (const int colIndex : nonZeroColIndicesInMat2[j])
          ans[i][colIndex] += mat1[i][j] * mat2[j][colIndex];
      }

    return ans;
  }
};
