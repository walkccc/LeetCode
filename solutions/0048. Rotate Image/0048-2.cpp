class Solution {
 public:
  void rotate(vector<vector<int>>& matrix) {
    for (int min = 0; min < matrix.size() / 2; ++min) {
      const int max = matrix.size() - min - 1;
      for (int i = min; i < max; ++i) {
        const int offset = i - min;
        const int top = matrix[min][i];
        matrix[min][i] = matrix[max - offset][min];
        matrix[max - offset][min] = matrix[max][max - offset];
        matrix[max][max - offset] = matrix[i][max];
        matrix[i][max] = top;
      }
    }
  }
};
