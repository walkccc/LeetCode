class Solution {
 public:
  long long maxCoins(vector<int>& lane1, vector<int>& lane2) {
    // dp[k] := the maximum number of coins at mile so far with k switches
    vector<long> dp = {lane1[0], lane2[0], LONG_MIN};
    long ans = ranges::max(dp);

    for (int i = 1; i < lane1.size(); ++i) {
      dp = {max(0L, dp[0]) + lane1[i],           //
            max({0L, dp[0], dp[1]}) + lane2[i],  //
            max(dp[1], dp[2]) + lane1[i]};
      ans = max(ans, ranges::max(dp));
    }

    return ans;
  }
};
