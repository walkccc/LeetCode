class Solution {
 public:
  long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
    vector<vector<pair<int, int>>> endToStartAndEarns(n + 1);
    // dp[i] := max dollars you can earn ending at i
    vector<long long> dp(n + 1);

    for (const auto& ride : rides) {
      const int start = ride[0];
      const int end = ride[1];
      const int tip = ride[2];
      const int earn = end - start + tip;
      endToStartAndEarns[end].emplace_back(start, earn);
    }

    for (int i = 1; i <= n; ++i) {
      dp[i] = dp[i - 1];
      for (const auto& [start, earn] : endToStartAndEarns[i])
        dp[i] = max(dp[i], dp[start] + earn);
    }

    return dp[n];
  }
};
