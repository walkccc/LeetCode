class Solution {
 public:
  long long maxScore(vector<int>& nums, int x) {
    // Note that we always need to take nums[0], so the initial definition might
    // not hold true.

    // dp0 := the maximum score so far with `nums` ending in an even number
    long long dp0 = nums[0] - (nums[0] % 2 == 1 ? x : 0);
    // dp1 := the maximum score so far with `nums` ending in an odd number
    long long dp1 = nums[0] - (nums[0] % 2 == 0 ? x : 0);

    for (int i = 1; i < nums.size(); ++i)
      if (nums[i] % 2 == 0)
        dp0 = nums[i] + max(dp0, dp1 - x);
      else
        dp1 = nums[i] + max(dp1, dp0 - x);

    return max(dp0, dp1);
  }
};
