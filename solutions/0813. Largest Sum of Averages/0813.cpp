class Solution {
 public:
  double largestSumOfAverages(vector<int>& nums, int k) {
    const int n = nums.size();
    // dp[i][k] := the maximum score to partition the first i nums into k groups
    dp.resize(n + 1, vector<double>(k + 1));
    prefix.resize(n + 1);

    partial_sum(nums.begin(), nums.end(), prefix.begin() + 1);
    return largestSumOfAverages(nums, n, k);
  }

 private:
  vector<vector<double>> dp;
  vector<double> prefix;

  double largestSumOfAverages(const vector<int>& nums, int i, int k) {
    if (k == 1)
      return prefix[i] / i;
    if (dp[i][k])
      return dp[i][k];

    // Try all the possible partitions.
    for (int j = k - 1; j < i; ++j)
      dp[i][k] = max(dp[i][k], largestSumOfAverages(nums, j, k - 1) +
                                   (prefix[i] - prefix[j]) / (i - j));

    return dp[i][k];
  }
};
