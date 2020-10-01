class Solution {
 public:
  int findTargetSumWays(vector<int>& nums, int S) {
    const int sum = accumulate(begin(nums), end(nums), 0);
    if (sum < S || (sum + S) & 1) return 0;

    return subsetSum(nums, (sum + S) / 2);
  }

 private:
  int subsetSum(const vector<int>& nums, int target) {
    vector<int> dp(target + 1);  // dp[i] := # of ways to sum to i
    dp[0] = 1;

    for (const int num : nums)
      for (int w = target; w >= num; --w)
        dp[w] += dp[w - num];

    return dp[target];
  }
};