class Solution {
 public:
  bool canPartition(vector<int>& nums) {
    const int sum = accumulate(begin(nums), end(nums), 0);
    if (sum & 1) return false;

    return subsetSum(nums, sum / 2);
  }

 private:
  bool subsetSum(const vector<int>& nums, int target) {
    vector<bool> dp(target + 1);  // dp[i] := true if can sum to i
    dp[0] = true;

    for (const int num : nums)
      for (int w = target; w >= num; --w)
        dp[w] = dp[w] || dp[w - num];

    return dp[target];
  }
};