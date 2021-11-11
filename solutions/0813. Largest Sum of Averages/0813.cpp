class Solution {
 public:
  double largestSumOfAverages(vector<int>& A, int K) {
    const int n = A.size();

    // dp[i][k] := largest score to partition first i nums into k groups
    dp.resize(n + 1, vector<double>(K + 1));
    prefix.resize(n + 1);

    for (int i = 0; i < n; ++i)
      prefix[i + 1] = A[i] + prefix[i];

    return largestSumOfAverages(A, n, K);
  }

 private:
  vector<vector<double>> dp;
  vector<double> prefix;

  double largestSumOfAverages(const vector<int>& A, int i, int k) {
    if (k == 1)
      return prefix[i] / i;
    if (dp[i][k])
      return dp[i][k];

    // try all possible partitions
    for (int j = k - 1; j < i; ++j)
      dp[i][k] = max(dp[i][k], largestSumOfAverages(A, j, k - 1) +
                                   (prefix[i] - prefix[j]) / (i - j));

    return dp[i][k];
  }
};
