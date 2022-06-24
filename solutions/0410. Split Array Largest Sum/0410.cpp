class Solution {
 public:
  int splitArray(vector<int>& nums, int m) {
    const int n = nums.size();
    // dp[i][k] := min of largest sum to split first i nums into k groups
    dp.resize(n + 1, vector<int>(m + 1, INT_MAX));
    prefix.resize(n + 1);

    partial_sum(begin(nums), end(nums), begin(prefix) + 1);
    return splitArray(nums, n, m);
  }

 private:
  vector<vector<int>> dp;
  vector<int> prefix;

  int splitArray(const vector<int>& nums, int i, int k) {
    if (k == 1)
      return prefix[i];
    if (dp[i][k] < INT_MAX)
      return dp[i][k];

    // try all possible partitions
    for (int j = k - 1; j < i; ++j)
      dp[i][k] =
          min(dp[i][k], max(splitArray(nums, j, k - 1), prefix[i] - prefix[j]));

    return dp[i][k];
  }
};
