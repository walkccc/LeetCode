class Solution {
 public:
  int minArraySum(vector<int>& nums, int k, int op1, int op2) {
    const int n = nums.size();
    // dp[i][j][k] := the minimum sum of nums[i..n - 1] with j operations of op1
    // and k operations of op2
    vector<vector<vector<int>>> dp(
        n + 1, vector<vector<int>>(op1 + 1, vector<int>(op2 + 1, INT_MAX)));

    // Base case: When index reaches the end of the array, the result is 0.
    for (int i = 0; i <= op1; ++i)
      for (int j = 0; j <= op2; ++j)
        dp[n][i][j] = 0;

    for (int i = n - 1; i >= 0; --i)
      for (int o1 = 0; o1 <= op1; ++o1)
        for (int o2 = 0; o2 <= op2; ++o2) {
          int sum = nums[i] + dp[i + 1][o1][o2];
          if (o1 > 0)
            sum = min(sum, (nums[i] + 1) / 2 + dp[i + 1][o1 - 1][o2]);
          if (o2 > 0 && nums[i] >= k)
            sum = min(sum, nums[i] - k + dp[i + 1][o1][o2 - 1]);
          if (o1 > 0 && o2 > 0) {
            if ((nums[i] + 1) / 2 >= k)
              sum = min(sum, (nums[i] + 1) / 2 - k + dp[i + 1][o1 - 1][o2 - 1]);
            if (nums[i] >= k)
              sum = min(sum, (nums[i] - k + 1) / 2 + dp[i + 1][o1 - 1][o2 - 1]);
          }
          dp[i][o1][o2] = sum;
        }

    return dp[0][op1][op2];
  }
};
