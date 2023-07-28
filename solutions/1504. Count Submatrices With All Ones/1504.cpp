class Solution {
 public:
  int numSubmat(vector<vector<int>>& mat) {
    const int m = mat.size();
    const int n = mat[0].size();
    int ans = 0;

    for (int baseRow = 0; baseRow < m; ++baseRow) {
      vector<int> row(n, 1);
      for (int i = baseRow; i < m; ++i) {
        for (int j = 0; j < n; ++j)
          row[j] &= mat[i][j];
        ans += count(row);
      }
    }

    return ans;
  }

 private:
  int count(vector<int>& row) {
    int ans = 0;
    int length = 0;

    for (const int a : row) {
      length = a == 0 ? 0 : length + 1;
      ans += length;
    }

    return ans;
  }
};
