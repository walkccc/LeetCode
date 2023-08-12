class Solution {
 public:
  long long getDescentPeriods(vector<int>& prices) {
    long long ans = 1;  // prices[0]
    int dp = 1;

    for (int i = 1; i < prices.size(); ++i) {
      if (prices[i] == prices[i - 1] - 1) {
        ++dp;
      } else {
        dp = 1;
      }
      ans += dp;
    }

    return ans;
  }
};
