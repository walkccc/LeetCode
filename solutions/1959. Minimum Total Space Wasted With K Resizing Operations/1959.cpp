class Solution {
 public:
  int minSpaceWastedKResizing(vector<int>& nums, int k) {
    // dp[i][k] := the minimum space wasted for nums[i..n) if you can resize k
    // times
    dp.resize(nums.size(), vector<int>(k + 1, -1));
    return minSpaceWasted(nums, 0, k);
  }

 private:
  static constexpr int kMax = 200'000'000;
  vector<vector<int>> dp;

  int minSpaceWasted(const vector<int>& nums, int i, int k) {
    if (i == nums.size())
      return 0;
    if (k == -1)
      return kMax;
    if (dp[i][k] != -1)
      return dp[i][k];

    int ans = kMax;
    int sum = 0;
    int maxNum = nums[i];

    for (int j = i; j < nums.size(); ++j) {
      sum += nums[j];
      maxNum = max(maxNum, nums[j]);
      const int wasted = maxNum * (j - i + 1) - sum;
      ans = min(ans, minSpaceWasted(nums, j + 1, k - 1) + wasted);
    }

    return dp[i][k] = ans;
  }
};
