class Solution {
 public:
  int shortestBridge(vector<vector<int>>& A) {
    markAsTwo(A);

    for (int color = 2;; ++color)
      for (int i = 0; i < A.size(); ++i)
        for (int j = 0; j < A[0].size(); ++j)
          if (A[i][j] == color)
            if (expand(A, i + 1, j, color) || expand(A, i - 1, j, color) ||
                expand(A, i, j + 1, color) || expand(A, i, j - 1, color))
              return color - 2;
  }

 private:
  // mark one group to 2s by DFS
  void markAsTwo(vector<vector<int>>& A) {
    for (int i = 0; i < A.size(); ++i)
      for (int j = 0; j < A[0].size(); ++j)
        if (A[i][j] == 1) {
          markAsTwo(A, i, j);
          return;
        }
  }

  void markAsTwo(vector<vector<int>>& A, int i, int j) {
    if (i < 0 || i == A.size() || j < 0 || j == A[0].size())
      return;
    if (A[i][j] != 1)
      return;

    A[i][j] = 2;
    markAsTwo(A, i + 1, j);
    markAsTwo(A, i - 1, j);
    markAsTwo(A, i, j + 1);
    markAsTwo(A, i, j - 1);
  }

  // expand from colors' group to 1s' group
  bool expand(vector<vector<int>>& A, int i, int j, int color) {
    if (i < 0 || i == A.size() || j < 0 || j == A[0].size())
      return false;
    if (A[i][j] == 0)
      A[i][j] = color + 1;
    return A[i][j] == 1;  // we touch the 1s' group!
  }
};
