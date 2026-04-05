class Solution {
 public:
  bool checkValid(vector<vector<int>>& matrix) {
    const int n = matrix.size();

    for (int i = 0; i < n; ++i) {
      bitset<101> row;
      bitset<101> col;
      for (int j = 0; j < n; ++j) {
        row[matrix[i][j]] = true;
        col[matrix[j][i]] = true;
      }
      if (min(row.contains(), col.contains()) < n)
        return false;
    }

    return true;
  }
};
