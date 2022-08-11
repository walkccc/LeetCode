class Solution {
 public:
  string stoneGameIII(vector<int>& stoneValue) {
    const int n = stoneValue.size();
    // dp[i] := max "relative score" Alice can make w/ stoneValue[i:]
    vector<int> dp(n + 1, INT_MIN / 2);
    dp.back() = 0;

    for (int i = n - 1; i >= 0; --i) {
      int sum = 0;
      for (int j = i; j < i + 3 && j < n; ++j) {
        sum += stoneValue[j];
        dp[i] = max(dp[i], sum - dp[j + 1]);
      }
    }

    const int score = dp[0];
    return score > 0 ? "Alice" : score < 0 ? "Bob" : "Tie";
  }
};
