class Solution {
 public:
  int maxValue(vector<vector<int>>& events, int k) {
    // dp[i][k] := max sum of events[i:] w/ max k # of attendance
    dp.resize(events.size(), vector<int>(k + 1, -1));
    sort(begin(events), end(events));
    return maxValue(events, 0, k);
  }

 private:
  vector<vector<int>> dp;

  int maxValue(const vector<vector<int>>& e, int i, int k) {
    if (k == 0 || i == e.size())
      return 0;
    if (dp[i][k] != -1)
      return dp[i][k];

    // binary search events to find the first index j s.t. e[j][0] > e[i][1]
    const auto it =
        upper_bound(begin(e) + i, end(e), e[i][1],
                    [](int end, const auto& a) { return a[0] > end; });
    const int j = distance(begin(e), it);
    return dp[i][k] =
               max(e[i][2] + maxValue(e, j, k - 1), maxValue(e, i + 1, k));
  }
};
