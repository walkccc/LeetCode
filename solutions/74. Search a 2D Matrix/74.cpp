class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty())
      return false;

    const int m = matrix.size();
    const int n = matrix[0].size();
    int l = 0;
    int r = m * n;

    while (l < r) {
      const int mid = (l + r) / 2;
      const int i = mid / n;
      const int j = mid % n;
      if (matrix[i][j] == target)
        return true;
      if (matrix[i][j] < target)
        l = mid + 1;
      else
        r = mid;
    }

    return false;
  }
};
