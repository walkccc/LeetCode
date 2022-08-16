class Solution {
 public:
  bool PredictTheWinner(vector<int>& nums) {
    const int n = nums.size();
    vector<int> dp = nums;

    for (int d = 1; d < n; ++d)
      for (int j = n - 1; j - d >= 0; --j) {
        const int i = j - d;
        dp[j] = max(nums[i] - dp[j],       // pick left num
                    nums[j] - dp[j - 1]);  // pick right num
      }

    return dp[n - 1] >= 0;
  }
};
