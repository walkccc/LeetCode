class NumMatrix {
 public:
  NumMatrix(vector<vector<int>>& matrix) {
    if (matrix.empty()) return;

    const int m = matrix.size();
    const int n = matrix[0].size();

    prefixSum = vector<vector<int>>(m + 1, vector<int>(n + 1));

    for (int i = 1; i <= m; ++i)
      for (int j = 1; j <= n; ++j)
        prefixSum[i][j] = matrix[i - 1][j - 1] + prefixSum[i - 1][j] +
                          prefixSum[i][j - 1] - prefixSum[i - 1][j - 1];
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    return prefixSum[row2 + 1][col2 + 1] - prefixSum[row1][col2 + 1] -
           prefixSum[row2 + 1][col1] + prefixSum[row1][col1];
  }

 private:
  vector<vector<int>> prefixSum;
};