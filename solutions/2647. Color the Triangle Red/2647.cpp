class Solution {
 public:
  vector<vector<int>> colorRed(int n) {
    vector<vector<int>> ans;
    const int tipSize = n % 4;

    // Tip of the triangle is always painted red.
    if (tipSize >= 1)
      ans.push_back({1, 1});

    // Paint most right and most left elements at the following rows.
    for (int i = 2; i <= tipSize; ++i) {
      ans.push_back({i, 1});
      ans.push_back({i, 2 * i - 1});
    }

    // Paint 4-row chunks.
    for (int i = tipSize + 1; i < n; i += 4) {
      // Fill the 1st row of the chunk.
      ans.push_back({i, 1});
      // Fill the 2nd row.
      for (int j = 1; j <= i; ++j)
        ans.push_back({i + 1, 2 * j + 1});
      // Fill the 3rd row.
      ans.push_back({i + 2, 2});
      // Fill the 4th row.
      for (int j = 0; j <= i + 2; ++j)
        ans.push_back({i + 3, 2 * j + 1});
    }

    return ans;
  }
};
