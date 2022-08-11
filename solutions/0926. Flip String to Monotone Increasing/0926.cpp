class Solution {
 public:
  int minFlipsMonoIncr(string S) {
    vector<int> dp(2);

    for (int i = 0; i < S.length(); ++i) {
      int temp = dp[0] + (S[i] == '1');
      dp[1] = min(dp[0], dp[1]) + (S[i] == '0');
      dp[0] = temp;
    }

    return min(dp[0], dp[1]);
  }
};
