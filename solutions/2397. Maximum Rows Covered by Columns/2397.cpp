class Solution {
 public:
  int maximumRows(vector<vector<int>>& matrix, int numSelect) {
    int ans = 0;
    dfs(matrix, /*colIndex=*/0, numSelect, /*mask=*/0, ans);
    return ans;
  }

 private:
  void dfs(const vector<vector<int>>& matrix, int colIndex, int leftColsCount,
           int mask, int& ans) {
    if (leftColsCount == 0) {
      ans = max(ans, getAllZerosRowCount(matrix, mask));
      return;
    }
    if (colIndex == matrix[0].size())
      return;

    // Choose this column.
    dfs(matrix, colIndex + 1, leftColsCount - 1, mask | 1 << colIndex, ans);
    // Don't choose this column.
    dfs(matrix, colIndex + 1, leftColsCount, mask, ans);
  }

  int getAllZerosRowCount(const vector<vector<int>>& matrix, int mask) {
    int count = 0;
    for (const vector<int>& row : matrix) {
      bool isAllZeros = true;
      for (int i = 0; i < row.size(); ++i) {
        if (row[i] == 1 && (mask >> i & 1) == 0) {
          isAllZeros = false;
          break;
        }
      }
      if (isAllZeros)
        ++count;
    }
    return count;
  }
};
