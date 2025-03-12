class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int r = 0;
    int c = matrix[0].size() - 1;

    while (r < matrix.size() && c >= 0) {
      if (matrix[r][c] == target)
        return true;
      if (matrix[r][c] > target)
        --c;
      else
        ++r;
    }

    return false;
  }
};
