class Solution {
 public:
  int minFallingPathSum(vector<vector<int>>& A) {
    const int n = A.size();

    for (int i = 1; i < n; ++i)
      for (int j = 0; j < n; ++j) {
        int mn = INT_MAX;
        for (int k = max(0, j - 1); k < min(n, j + 2); ++k)
          mn = min(mn, A[i - 1][k]);
        A[i][j] += mn;
      }

    return ranges::min(A[n - 1]);
  }
};
