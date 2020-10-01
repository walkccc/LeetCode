class Solution {
 public:
  double largestSumOfAverages(vector<int>& A, int K) {
    const int n = A.size();

    // dp[i][k] := largest score to partition first i nums into k groups
    vector<vector<double>> dp(n + 1, vector<double>(K + 1, 0.0));
    vector<double> prefixSum(n + 1);

    for (int i = 1; i <= n; ++i) {
      prefixSum[i] += prefixSum[i - 1] + A[i - 1];
      dp[i][1] = prefixSum[i] / i;
    }

    for (int k = 2; k <= K; ++k)
      for (int i = k; i <= n; ++i)
        for (int j = k - 1; j < i; ++j) {
          const double average = (prefixSum[i] - prefixSum[j]) / (i - j);
          dp[i][k] = max(dp[i][k], dp[j][k - 1] + average);
        }

    return dp[n][K];
  }
};