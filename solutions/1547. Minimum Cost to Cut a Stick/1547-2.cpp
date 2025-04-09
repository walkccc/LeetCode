class Solution {
 public:
  int minCost(int n, vector<int>& cuts) {
    cuts.push_back(0);
    cuts.push_back(n);
    ranges::sort(cuts);

    // dp[i][j] := minCost(cuts[i..j])
    vector<vector<int>> dp(cuts.size(), vector<int>(cuts.size()));

    for (int d = 2; d < cuts.size(); ++d)
      for (int i = 0; i + d < cuts.size(); ++i) {
        const int j = i + d;
        dp[i][j] = INT_MAX;
        for (int k = i + 1; k < j; ++k)
          dp[i][j] = min(dp[i][j], cuts[j] - cuts[i] + dp[i][k] + dp[k][j]);
      }

    return dp[0][cuts.size() - 1];
  }
};
