class Solution {
 public:
  vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
    vector<int> ans;
    vector<vector<int>> rowSum;

    for (int i = 0; i < mat.size(); ++i)
      rowSum.push_back({accumulate(mat[i].begin(), mat[i].end(), 0), i});

    ranges::sort(rowSum, [](const auto& a, const auto& b) {
      return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
    });

    for (int i = 0; i < k; ++i)
      ans.push_back(rowSum[i][1]);

    return ans;
  }
};
