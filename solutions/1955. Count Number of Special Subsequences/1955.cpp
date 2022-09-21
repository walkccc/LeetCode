class Solution {
 public:
  int countSpecialSubsequences(vector<int>& nums) {
    // dp[i][j] := # of special subseqs of nums[i:] and prev + 1 = j
    dp.resize(nums.size(), vector<int>(4, -1));
    return countSpecialSubsequences(nums, 0, -1);
  }

 private:
  constexpr static int kMod = 1'000'000'007;
  vector<vector<int>> dp;

  int countSpecialSubsequences(const vector<int>& nums, int i, int prev) {
    if (i == nums.size())
      return prev == 2;
    if (dp[i][prev + 1] != -1)
      return dp[i][prev + 1];

    long ans = 0;

    // not include nums[i]
    ans += countSpecialSubsequences(nums, i + 1, prev);

    // include nums[i]
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
