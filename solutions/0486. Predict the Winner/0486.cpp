class Solution {
 public:
  bool PredictTheWinner(vector<int>& nums) {
    const int n = nums.size();

    vector<int> dp = nums;

    for (int length = 2; length <= n; ++length)
      for (int i = n - 1; i - length + 1 >= 0; --i)
        dp[i] = max(nums[i] - dp[i - 1],            // pick right num
                    nums[i - length + 1] - dp[i]);  // pick left num

    return dp.back() >= 0;
  }
};