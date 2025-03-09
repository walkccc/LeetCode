class Solution {
 public:
  vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
    vector<vector<int>> ans(n, vector<int>(n));
    vector<vector<int>> prefix(n, vector<int>(n + 1));

    for (const vector<int>& query : queries) {
      const int row1 = query[0];
      const int col1 = query[1];
      const int row2 = query[2];
      const int col2 = query[3];
      for (int i = row1; i <= row2; ++i) {
        ++prefix[i][col1];
        --prefix[i][col2 + 1];
      }
    }

    for (int i = 0; i < n; ++i) {
      int sum = 0;
      for (int j = 0; j < n; ++j) {
        sum += prefix[i][j];
        ans[i][j] = sum;
      }
    }

    return ans;
  }
};
