class Solution {
 public:
  int countSquares(vector<vector<int>>& matrix) {
    for (int i = 0; i < matrix.size(); ++i)
      for (int j = 0; j < matrix[0].size(); ++j)
        if (matrix[i][j] == 1 && i > 0 && j > 0)
          matrix[i][j] +=
              min({matrix[i - 1][j - 1], matrix[i - 1][j], matrix[i][j - 1]});
    return accumulate(matrix.begin(), matrix.end(), 0,
                      [](int subtotal, const vector<int>& row) {
      return subtotal + accumulate(row.begin(), row.end(), 0);
    });
  }
};
