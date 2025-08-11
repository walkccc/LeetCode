class Solution {
 public:
  double maxAmount(string initialCurrency, vector<vector<string>>& pairs1,
                   vector<double>& rates1, vector<vector<string>>& pairs2,
                   vector<double>& rates2) {
    // dp[currency] := the maximum amount of money to convert to `currency`
    unordered_map<string, double> dp{{initialCurrency, 1}};
    bellman(dp, pairs1, rates1);
    bellman(dp, pairs2, rates2);
    return dp[initialCurrency];
  }

 private:
  void bellman(unordered_map<string, double>& dp,
               const vector<vector<string>>& pairs,
               const vector<double>& rates) {
    for (int relax = 0; relax < pairs.size(); ++relax)
      for (int i = 0; i < pairs.size(); ++i) {
        const string start = pairs[i][0];
        const string target = pairs[i][1];
        dp[target] = max(dp[target], dp[start] * rates[i]);
        dp[start] = max(dp[start], dp[target] / rates[i]);
      }
  }
};
