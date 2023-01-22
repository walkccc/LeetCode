class Solution {
 public:
  double largestSumOfAverages(vector<int>& nums, int K) {
    const int n = nums.size();
    // dp[i][k] := largest score to partition first i nums into k groups
    vector<vector<double>> dp(n + 1, vector<double>(K + 1));
    vector<double> prefix(n + 1);

    partial_sum(begin(nums), end(nums), begin(prefix) + 1);

    for (int i = 1; i <= n; ++i)
      dp[i][1] = prefix[i] / i;

    for (int k = 2; k <= K; ++k)
      for (int i = k; i <= n; ++i)
        for (int j = k - 1; j < i; ++j) {
          const double average = (prefix[i] - prefix[j]) / (i - j);
          dp[i][k] = max(dp[i][k], dp[j][k - 1] + average);
        }

    return dp[n][K];
  }
};
