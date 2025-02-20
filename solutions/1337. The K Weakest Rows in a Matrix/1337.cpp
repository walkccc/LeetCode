class Solution {
 public:
  vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
    vector<int> ans;
    vector<pair<int, int>> rowSums;  // (sum(mat[i]), i)

    for (int i = 0; i < mat.size(); ++i)
      rowSums.emplace_back(accumulate(mat[i].begin(), mat[i].end(), 0), i);

    ranges::sort(rowSums, ranges::less{},
                 [](const pair<int, int>& rowSum) { return rowSum; });

    for (int i = 0; i < k; ++i)
      ans.push_back(rowSums[i].second);

    return ans;
  }
};
