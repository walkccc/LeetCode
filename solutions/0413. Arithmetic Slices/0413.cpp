class Solution {
 public:
  int numberOfArithmeticSlices(vector<int>& nums) {
    const int n = nums.size();
    if (n < 3)
      return 0;

    vector<int> dp(n);  // # arithmetic slices ends at i

    for (int i = 2; i < nums.size(); ++i)
      if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])
        dp[i] = dp[i - 1] + 1;

    return accumulate(begin(dp), end(dp), 0);
  }
};
