class Solution {
 public:
  int countSpecialSubsequences(vector<int>& nums) {
    // dp[i][j] := the number of increasing subsequences of the first i numbers,
    // where the the previous number is j - 1
    dp.resize(nums.size(), vector<int>(4, -1));
    return countSpecialSubsequences(nums, 0, -1);
  }

 private:
  static constexpr int kMod = 1'000'000'007;
  vector<vector<int>> dp;

  int countSpecialSubsequences(const vector<int>& nums, int i, int prev) {
    if (i == nums.size())
      return prev == 2;
    if (dp[i][prev + 1] != -1)
      return dp[i][prev + 1];

    long ans = 0;

    // Don't include the `nums[i]`.
    ans += countSpecialSubsequences(nums, i + 1, prev);

    // Include the `nums[i]`.
    if (nums[i] == prev)
      ans += countSpecialSubsequences(nums, i + 1, prev);
    if (prev == -1 && nums[i] == 0)
      ans += countSpecialSubsequences(nums, i + 1, 0);
    if (prev == 0 && nums[i] == 1)
      ans += countSpecialSubsequences(nums, i + 1, 1);
    if (prev == 1 && nums[i] == 2)
      ans += countSpecialSubsequences(nums, i + 1, 2);

    ans %= kMod;
    return dp[i][prev + 1] = ans;
  }
};
