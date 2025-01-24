class Solution {
 public:
  int maxCoins(vector<int>& nums) {
    const int n = nums.size();
    // dp[i][j] := maxCoins(nums[i..j])
    vector<vector<int>> dp(n + 2, vector<int>(n + 2));

    nums.insert(nums.begin(), 1);
    nums.insert(nums.end(), 1);

    for (int d = 0; d < n; ++d)
      for (int i = 1; i + d <= n; ++i) {
        const int j = i + d;
        for (int k = i; k <= j; ++k)
          dp[i][j] = max(dp[i][j],                      //
                         dp[i][k - 1] + dp[k + 1][j] +  //
                             nums[i - 1] * nums[k] * nums[j + 1]);
      }

    return dp[1][n];
  }
};
