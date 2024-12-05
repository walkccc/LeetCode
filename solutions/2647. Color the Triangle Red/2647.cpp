class Solution {
 public:
  vector<vector<int>> colorRed(int n) {
    vector<vector<int>> ans;
    const int tipSize = n % 4;

    // The tip of the triangle is always painted red.
    if (tipSize >= 1)
      ans.push_back({1, 1});

    // Paint the rightmost and the leftmost elements at the following rows.
    for (int i = 2; i <= tipSize; ++i) {
      ans.push_back({i, 1});
      ans.push_back({i, 2 * i - 1});
    }

    // Paint the 4-row chunks.
    for (int i = tipSize + 1; i < n; i += 4) {
      // Fill the first row of the chunk.
      ans.push_back({i, 1});
      // Fill the second row.
      for (int j = 1; j <= i; ++j)
        ans.push_back({i + 1, 2 * j + 1});
      // Fill the third row.
      ans.push_back({i + 2, 2});
      // Fill the fourth row.
      for (int j = 0; j <= i + 2; ++j)
        ans.push_back({i + 3, 2 * j + 1});
    }

    return ans;
  }
};
