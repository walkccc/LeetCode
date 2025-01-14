class Solution {
 public:
  vector<int> luckyNumbers(vector<vector<int>>& matrix) {
    for (const vector<int>& row : matrix) {
      const int minIndex = distance(row.begin(), ranges::min_element(row));
      if (row[minIndex] == maxNumOfColumn(matrix, minIndex))
        return {row[minIndex]};
    }
    return {};
  }

 private:
  int maxNumOfColumn(const vector<vector<int>>& matrix, int j) {
    int res = 0;
    for (int i = 0; i < matrix.size(); ++i)
      res = max(res, matrix[i][j]);
    return res;
  }
};
