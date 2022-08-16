class Solution {
 public:
  vector<vector<int>> minScore(vector<vector<int>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();
    vector<vector<int>> ans(m, vector<int>(n));
    vector<array<int, 3>> valAndIndices;
    vector<int> rows(m);  // rows[i] := max used number so far
    vector<int> cols(n);  // cols[j] := max used number so far

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        valAndIndices.push_back({grid[i][j], i, j});

    sort(begin(valAndIndices), end(valAndIndices));

    for (const auto& [_, i, j] : valAndIndices) {
      const int nextAvailable = max(rows[i], cols[j]) + 1;
      ans[i][j] = nextAvailable;
      rows[i] = nextAvailable;
      cols[j] = nextAvailable;
    }

    return ans;
  }
};
