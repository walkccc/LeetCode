class Solution {
 public:
  double probabilityOfHeads(vector<double>& prob, int target) {
    // dp[j] := the probability of tossing the coins so far with j heads
    vector<double> dp(target + 1);
    dp[0] = 1.0;

    for (const double p : prob)
      for (int j = target; j >= 0; --j)
        dp[j] = (j > 0 ? dp[j - 1] * p : 0) + dp[j] * (1 - p);

    return dp[target];
  }
};
