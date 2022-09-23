class Solution {
 public:
  double largestSumOfAverages(vector<int>& nums, int K) {
    const int n = nums.size();
    // dp[i][k] := largest score to partition first i nums into k groups
    dp.resize(n + 1, vector<double>(K + 1));
    prefix.resize(n + 1);

    partial_sum(begin(nums), end(nums), begin(prefix) + 1);
    return largestSumOfAverages(nums, n, K);
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
