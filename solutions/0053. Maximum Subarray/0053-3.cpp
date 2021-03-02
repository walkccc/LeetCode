class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    // dp[i] := max sum subarray ending w/ nums[i]
    vector<int> dp(nums.size());

    for (int i = 0; i < nums.size(); ++i)
      if (i > 0 && dp[i - 1] > 0)
        dp[i] = dp[i - 1] + nums[i];
      else
        dp[i] = nums[i];

    return *max_element(begin(dp), end(dp));
  }
};
