class Solution {
 public:
  bool checkXMatrix(vector<vector<int>>& grid) {
    const int n = grid.size();

    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        if (i == j || i + j == n - 1) {  // in diagonal
          if (grid[i][j] == 0)
            return false;
        } else if (grid[i][j]) {  // not in diagonal
          return false;
        }

    return true;
  }
};
