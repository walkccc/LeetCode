class Solution {
 public:
  int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
    const int m = matrix.size();
    const int n = matrix[0].size();
    int ans = 0;
    vector<int> flip(n);
    unordered_set<int> seen;

    for (int i = 0; i < m; ++i) {
      if (seen.count(i))
        continue;
      int count = 0;
      for (int j = 0; j < n; ++j)
        flip[j] = 1 ^ matrix[i][j];
      for (int k = 0; k < m; ++k)
        if (matrix[k] == matrix[i] || matrix[k] == flip) {
          seen.insert(k);
          ++count;
        }
      ans = max(ans, count);
    }

    return ans;
  }
};
