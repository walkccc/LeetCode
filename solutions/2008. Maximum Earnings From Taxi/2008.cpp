class Solution {
 public:
  long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
    vector<vector<pair<int, int>>> startToEndAndEarns(n);
    // dp[i] := the maximum dollars you can earn starting at i
    vector<long> dp(n + 1);

    for (const vector<int>& ride : rides) {
      const int start = ride[0];
      const int end = ride[1];
      const int tip = ride[2];
      const int earn = end - start + tip;
      startToEndAndEarns[start].emplace_back(end, earn);
    }

    for (int i = n - 1; i >= 1; --i) {
      dp[i] = dp[i + 1];
      for (const auto& [end, earn] : startToEndAndEarns[i])
        dp[i] = max(dp[i], dp[end] + earn);
    }

    return dp[1];
  }
};
