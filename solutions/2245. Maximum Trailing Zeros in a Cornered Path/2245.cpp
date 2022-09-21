class Solution {
 public:
  int maxTrailingZeros(vector<vector<int>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();
    // leftPrefix2[i][j] := # of 2 in grid[i][0..j]
    // leftPrefix5[i][j] := # of 5 in grid[i][0..j]
    // topPrefix2[i][j] := # of 2 in grid[0..i][j]
    // topPrefix5[i][j] := # of 5 in grid[0..i][j]
    vector<vector<int>> leftPrefix2(m, vector<int>(n));
    vector<vector<int>> leftPrefix5(m, vector<int>(n));
    vector<vector<int>> topPrefix2(m, vector<int>(n));
    vector<vector<int>> topPrefix5(m, vector<int>(n));

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        leftPrefix2[i][j] = getCount(grid[i][j], 2);
        leftPrefix5[i][j] = getCount(grid[i][j], 5);
        if (j) {
          leftPrefix2[i][j] += leftPrefix2[i][j - 1];
          leftPrefix5[i][j] += leftPrefix5[i][j - 1];
        }
      }

    for (int j = 0; j < n; ++j)
      for (int i = 0; i < m; ++i) {
        topPrefix2[i][j] = getCount(grid[i][j], 2);
        topPrefix5[i][j] = getCount(grid[i][j], 5);
        if (i) {
          topPrefix2[i][j] += topPrefix2[i - 1][j];
          topPrefix5[i][j] += topPrefix5[i - 1][j];
        }
      }

    int ans = 0;
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        const int curr2 = getCount(grid[i][j], 2);
        const int curr5 = getCount(grid[i][j], 5);
        const int l2 = leftPrefix2[i][j];
        const int l5 = leftPrefix5[i][j];
        const int r2 = leftPrefix2[i][n - 1] - (j ? leftPrefix2[i][j - 1] : 0);
        const int r5 = leftPrefix5[i][n - 1] - (j ? leftPrefix5[i][j - 1] : 0);
        const int t2 = topPrefix2[i][j];
        const int t5 = topPrefix5[i][j];
        const int d2 = topPrefix2[m - 1][j] - (i ? topPrefix2[i - 1][j] : 0);
        const int d5 = topPrefix5[m - 1][j] - (i ? topPrefix5[i - 1][j] : 0);
        ans = max({ans, min(l2 + t2 - curr2, l5 + t5 - curr5),
                   min(r2 + t2 - curr2, r5 + t5 - curr5),
                   min(l2 + d2 - curr2, l5 + d5 - curr5),
                   min(r2 + d2 - curr2, r5 + d5 - curr5)});
      }

    return ans;
  }

 private:
  int getCount(int num, int factor) {
    int count = 0;
    while (num % factor == 0) {
      num /= factor;
      ++count;
    }
    return count;
  }
};
