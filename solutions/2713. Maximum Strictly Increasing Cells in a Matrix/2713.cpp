class Solution {
 public:
  int maxIncreasingCells(vector<vector<int>>& mat) {
    const int m = mat.size();
    const int n = mat[0].size();
    vector<int> rows(m);  // rows[i] := max path length for i-th row
    vector<int> cols(n);  // cols[j] := max path length for j-th col
    unordered_map<int, vector<pair<int, int>>> valToIndices;
    // maxPathLength[i][j] := max path length from mat[i][j]
    vector<vector<int>> maxPathLength(m, vector<int>(n));
    // all unique values in the matrix in non-increasing order
    set<int, greater<>> decreasingSet;

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        valToIndices[mat[i][j]].emplace_back(i, j);
        decreasingSet.insert(mat[i][j]);
      }

    for (const int val : decreasingSet) {
      for (const auto& [i, j] : valToIndices[val])
        maxPathLength[i][j] = max(rows[i], cols[j]) + 1;
      for (const auto& [i, j] : valToIndices[val]) {
        rows[i] = max(rows[i], maxPathLength[i][j]);
        cols[j] = max(cols[j], maxPathLength[i][j]);
      }
    }

    return max(ranges::max(rows), ranges::max(cols));
  }
};
