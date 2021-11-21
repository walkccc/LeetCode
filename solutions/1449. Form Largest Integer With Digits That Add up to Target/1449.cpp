class Solution {
 public:
  string largestNumber(vector<int>& cost, int target) {
    // dp[i] := max length that cost i can achieve
    vector<int> dp(target + 1, INT_MIN);
    dp[0] = 0;  // when cost = 0, the best is empty string ""

    for (int i = 1; i <= target; ++i)
      for (int d = 0; d < 9; ++d)
        if (i >= cost[d])
          dp[i] = max(dp[i], dp[i - cost[d]] + 1);

    if (dp[target] < 0)
      return "0";

    string ans;

    // greedily build the ans string
    for (int d = 8; d >= 0; --d)
      while (target >= cost[d] && dp[target] == dp[target - cost[d]] + 1) {
        target -= cost[d];
        ans += '1' + d;
      }

    return ans;
  }
};
