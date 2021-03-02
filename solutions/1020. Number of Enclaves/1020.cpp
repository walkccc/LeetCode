class Solution {
 public:
  int numEnclaves(vector<vector<int>>& A) {
    const int m = A.size();
    const int n = A[0].size();

    // remove lands connected to edge
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (i * j == 0 || i == m - 1 || j == n - 1)
          if (A[i][j] == 1)
            dfs(A, i, j);

    return accumulate(begin(A), end(A), 0, [](int s, vector<int>& row) {
      return s + accumulate(begin(row), end(row), 0);
    });
  }

 private:
  void dfs(vector<vector<int>>& A, int i, int j) {
    if (i < 0 || i == A.size() || j < 0 || j == A[0].size())
      return;
    if (A[i][j] == 0)
      return;

    A[i][j] = 0;
    dfs(A, i + 1, j);
    dfs(A, i - 1, j);
    dfs(A, i, j + 1);
    dfs(A, i, j - 1);
  };
};
