class Solution {
 public:
  int maxCoins(vector<int>& nums) {
    const int n = nums.size();

    nums.insert(begin(nums), 1);
    nums.insert(end(nums), 1);

    // dp[i][j] := maxCoins(nums[i..j])
    vector<vector<int>> dp(n + 2, vector<int>(n + 2));

    for (int length = 1; length <= n; ++length)
      for (int i = 1; i + length - 1 <= n; ++i) {
        const int j = i + length - 1;
        for (int k = i; k <= j; ++k)
          dp[i][j] = max(dp[i][j], dp[i][k - 1] + dp[k + 1][j] +
                                       nums[i - 1] * nums[k] * nums[j + 1]);
      }

    return dp[1][n];
  }
};