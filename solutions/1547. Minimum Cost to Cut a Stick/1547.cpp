class Solution {
 public:
  int minCost(int n, vector<int>& cuts) {
    cuts.push_back(0);
    cuts.push_back(n);
    sort(begin(cuts), end(cuts));

    // dp[i][j] := minCost(cuts[i..j])
    dp.resize(cuts.size(), vector<int>(cuts.size()));
    return minCost(cuts, 0, cuts.size() - 1);
  }

 private:
  vector<vector<int>> dp;

  int minCost(const vector<int>& cuts, int i, int j) {
    if (j - i <= 1)
      return 0;
    if (dp[i][j])
      return dp[i][j];

    dp[i][j] = INT_MAX;

    for (int k = i + 1; k < j; ++k)
      dp[i][j] = min(dp[i][j], cuts[j] - cuts[i] + minCost(cuts, i, k) +
                                   minCost(cuts, k, j));

    return dp[i][j];
  }
};
