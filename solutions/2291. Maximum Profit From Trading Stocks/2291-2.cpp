class Solution {
 public:
  int maximumProfit(vector<int>& present, vector<int>& future, int budget) {
    const int n = present.size();
    // dp[i] := the maximum profit of buying present so far with i budget
    vector<int> dp(budget + 1);

    for (int i = 0; i < n; ++i)
      for (int j = budget; j >= present[i]; --j)
        dp[j] = max(dp[j], future[i] - present[i] + dp[j - present[i]]);

    return dp[budget];
  }
};
