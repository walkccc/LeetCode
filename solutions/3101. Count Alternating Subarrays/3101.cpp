class Solution {
 public:
  long long countAlternatingSubarrays(vector<int>& nums) {
    // dp[i] := the number of alternating subarrays ending in index i
    vector<long> dp(nums.size(), 1);

    for (int i = 1; i < nums.size(); ++i)
      if (nums[i] != nums[i - 1])
        dp[i] += dp[i - 1];

    return accumulate(dp.begin(), dp.end(), 0L);
  }
};
