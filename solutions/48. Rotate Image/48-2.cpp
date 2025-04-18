class Solution {
 public:
  void rotate(vector<vector<int>>& matrix) {
    for (int mn = 0; mn < matrix.size() / 2; ++mn) {
      const int mx = matrix.size() - mn - 1;
      for (int i = mn; i < mx; ++i) {
        const int offset = i - mn;
        const int top = matrix[mn][i];
        matrix[mn][i] = matrix[mx - offset][mn];
        matrix[mx - offset][mn] = matrix[mx][mx - offset];
        matrix[mx][mx - offset] = matrix[i][mx];
        matrix[i][mx] = top;
      }
    }
  }
};
