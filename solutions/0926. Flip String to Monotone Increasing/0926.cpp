class Solution {
 public:
  int minFlipsMonoIncr(string s) {
    vector<int> dp(2);

    for (const char c : s) {
      const int temp = dp[0] + (c == '1');
      dp[1] = min(dp[0], dp[1]) + (c == '0');
      dp[0] = temp;
    }

    return min(dp[0], dp[1]);
  }
};
