class Solution {
 public:
  int tribonacci(int n) {
    vector<int> dp{0, 1, 1};

    for (int i = 3; i <= n; ++i)
      dp[i % 3] = dp[0] + dp[1] + dp[2];

    return dp[n % 3];
  }
};
