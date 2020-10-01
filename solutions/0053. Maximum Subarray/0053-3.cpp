class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    const int n = nums.size();

    // dp[i] := sum of the subarray with max sum ending w/ nums[i]
    vector<int> dp(n);
    dp[0] = nums[0];

    for (int i = 1; i < n; ++i)
      dp[i] = (dp[i - 1] > 0 ? dp[i - 1] : 0) + nums[i];

    return *max_element(begin(dp), end(dp));
  }
};