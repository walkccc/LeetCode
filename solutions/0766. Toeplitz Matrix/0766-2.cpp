class Solution {
 public:
  bool isToeplitzMatrix(vector<vector<int>>& matrix) {
    if (matrix.empty())
      return true;

    const int m = matrix.size();
    const int n = matrix[0].size();
    vector<int> buffer(n);

    // Load row[0] to buffer
    for (int j = 0; j < n; ++j)
      buffer[j] = matrix[0][j];

    // Do rolling array
    for (int i = 1; i < m; ++i) {
      for (int j = 0; j + 1 < n; ++j)
        if (buffer[j] != matrix[i][j + 1])
          return false;
      buffer = matrix[i];
    }

    return true;
  }
};
