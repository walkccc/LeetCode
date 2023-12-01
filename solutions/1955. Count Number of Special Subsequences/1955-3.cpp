class Solution {
 public:
  int countSpecialSubsequences(vector<int>& nums) {
    constexpr int kMod = 1'000'000'007;
    const int n = nums.size();
    // dp[j] := the number of increasing subsequences of the numbers so far that
    // end in j
    vector<long> dp(3);

    if (nums[0] == 0)
      dp[0] = 1;

    for (int i = 1; i < n; ++i) {
      if (nums[i] == 0)
        dp[0] = dp[0] * 2 + 1;
      else if (nums[i] == 1)
        dp[1] = dp[1] * 2 + dp[0];
      else  // nums[i] == 2
        dp[2] = dp[2] * 2 + dp[1];

      for (int ending = 0; ending < 3; ++ending)
        dp[ending] %= kMod;
    }

    return dp[2];
  }
};
