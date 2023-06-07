class Solution {
 public:
  bool canPartition(vector<int>& nums) {
    const int sum = accumulate(begin(nums), end(nums), 0);
    if (sum & 1)
      return false;
    return knapsack(nums, sum / 2);
  }

 private:
  bool knapsack(const vector<int>& nums, int subsetSum) {
    // dp[i] := true if i can be formed by nums so far
    vector<bool> dp(subsetSum + 1);
    dp[0] = true;

    for (const int num : nums)
      for (int i = subsetSum; i >= num; --i)
        dp[i] = dp[i] || dp[i - num];

    return dp[subsetSum];
  }
};
