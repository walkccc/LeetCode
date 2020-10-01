class Solution {
 public:
  double largestSumOfAverages(vector<int>& A, int K) {
    const int n = A.size();

    vector<vector<double>> memo(n + 1, vector<double>(K + 1, 0.0));
    vector<double> prefixSum(n + 1);

    for (int i = 1; i <= n; ++i)
      prefixSum[i] += prefixSum[i - 1] + A[i - 1];

    // dp(n, K) := largest score to partition A[0..i) into k groups
    function<double(int, int)> dp = [&](int n, int K) {
      if (K == 1) return prefixSum[n] / n;
      double& ans = memo[n][K];
      if (ans > 0.0) return ans;

      // try all possible partitions
      for (int i = K - 1; i < n; ++i)
        ans = max(ans, dp(i, K - 1) + (prefixSum[n] - prefixSum[i]) / (n - i));

      return ans;
    };

    return dp(n, K);
  }
};