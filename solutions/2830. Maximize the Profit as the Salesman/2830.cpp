class Solution {
 public:
  int maximizeTheProfit(int n, vector<vector<int>>& offers) {
    // dp[i] := the maximum amount of gold of selling the first i houses
    vector<int> dp(n + 1);
    vector<vector<pair<int, int>>> endToStartAndGolds(n);

    for (const vector<int>& offer : offers) {
      const int start = offer[0];
      const int end = offer[1];
      const int gold = offer[2];
      endToStartAndGolds[end].emplace_back(start, gold);
    }

    for (int end = 1; end <= n; ++end) {
      // Get at least the same gold as selling the first `end - 1` houses.
      dp[end] = dp[end - 1];
      for (const auto& [start, gold] : endToStartAndGolds[end - 1])
        dp[end] = max(dp[end], dp[start] + gold);
    }

    return dp[n];
  }
};
