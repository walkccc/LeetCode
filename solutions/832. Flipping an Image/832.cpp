class Solution {
 public:
  vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
    const int n = A.size();

    for (int i = 0; i < n; ++i)
      for (int j = 0; j < (n + 1) / 2; ++j) {
        const int temp = A[i][j];
        A[i][j] = A[i][n - j - 1] ^ 1;
        A[i][n - j - 1] = temp ^ 1;
      }

    return A;
  }
};
