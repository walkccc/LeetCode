class Solution {
 public:
  int minMoves(vector<vector<int>>& rooks) {
    const int n = rooks.size();
    int ans = 0;
    vector<vector<int>> sortedByRow(rooks);
    vector<vector<int>> sortedByCol(rooks);

    ranges::sort(sortedByRow, ranges::less{},
                 [](const vector<int>& rook) { return rook[0]; });

    ranges::sort(sortedByCol, ranges::less{},
                 [](const vector<int>& rook) { return rook[1]; });

    for (int i = 0; i < n; ++i) {
      ans += abs(sortedByRow[i][0] - /*targetRow=*/i);
      ans += abs(sortedByCol[i][1] - /*targetCol=*/i);
    }

    return ans;
  }
};
