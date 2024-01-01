class Solution {
 public:
  int rob(vector<int>& nums) {
    if (nums.empty())
      return 0;
    if (nums.size() == 1)
      return nums[0];

    // dp[i] := the maximum money of robbing nums[0..i]
    vector<int> dp(nums.size());
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for (int i = 2; i < nums.size(); ++i)
      dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);

    return dp.back();
  }
};
