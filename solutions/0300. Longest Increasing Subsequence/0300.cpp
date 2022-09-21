class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    if (nums.empty())
      return 0;

    // dp[i] := length of LIS ending at nums[i]
    vector<int> dp(nums.size(), 1);

    for (int i = 1; i < nums.size(); ++i)
      for (int j = 0; j < i; ++j)
        if (nums[j] < nums[i])
          dp[i] = max(dp[i], dp[j] + 1);

    return *max_element(begin(dp), end(dp));
  }
};
