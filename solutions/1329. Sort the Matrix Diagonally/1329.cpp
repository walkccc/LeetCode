class Solution {
 public:
  vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
    const int m = mat.size();
    const int n = mat[0].size();

    unordered_map<int, priority_queue<int>> count;

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) count[i - j].push(mat[i][j]);

    for (int i = m - 1; i >= 0; --i)
      for (int j = n - 1; j >= 0; --j)
        mat[i][j] = count[i - j].top(), count[i - j].pop();

    return mat;
  }
};
