class Solution {
 public:
  int sumOfPower(vector<int>& nums, int k) {
    constexpr int kMod = 1'000'000'007;
    const int n = nums.size();
    // dp[i][j] := the number of subsequences in nums[0..i) that sums to k
    vector<vector<int>> dp(n + 1, vector<int>(k + 1));
    dp[0][0] = 1;

    for (int i = 1; i <= n; ++i) {
      const int num = nums[i - 1];
      for (int j = 0; j <= k; ++j)
        if (j < num)
          // 1. Exclude nums[i] in the subsequence.
          // 2. Include nums[i] in the subsequence and skip it.
          dp[i][j] = (dp[i - 1][j] * 2L) % kMod;
        else
          // 1. Exclude nums[i] in the subsequence.
          // 2. Include nums[i] in the subsequence and skip it.
          // 3. Include nums[i] in the subsequence and pick it.
          dp[i][j] = (dp[i - 1][j] * 2L + dp[i - 1][j - num]) % kMod;
    }

    return dp[n][k];
  }
};
