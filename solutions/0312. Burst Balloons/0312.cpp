class Solution {
 public:
  int maxCoins(vector<int>& nums) {
    const int n = nums.size();

    nums.insert(begin(nums), 1);
    nums.insert(end(nums), 1);

    // dp[i][j] := maxCoins(nums[i..j])
    dp.resize(n + 2, vector<int>(n + 2));
    return maxCoins(nums, 1, n);
  }

 private:
  vector<vector<int>> dp;

  int maxCoins(vector<int>& nums, int i, int j) {
    if (i > j)
      return 0;
    if (dp[i][j])
      return dp[i][j];

    for (int k = i; k <= j; ++k)
      dp[i][j] = max(dp[i][j],
                     maxCoins(nums, i, k - 1) +
                     maxCoins(nums, k + 1, j) +
                     nums[i - 1] * nums[k] * nums[j + 1]);

    return dp[i][j];
  }
};
