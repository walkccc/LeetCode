class Solution {
 public:
  int maxScore(vector<int>& nums) {
    const int n = nums.size() / 2;
    // dp[i][j] := the maximum score of the i to n operations with j mask
    dp.resize(n + 1, vector<int>(1 << n * 2));
    return maxScore(nums, 1, 0);
  }

 private:
  vector<vector<int>> dp;

  int maxScore(const vector<int>& nums, int op, int mask) {
    if (op == dp.size())
      return 0;
    if (dp[op][mask] > 0)
      return dp[op][mask];

    for (int i = 0; i < nums.size(); ++i)
      for (int j = i + 1; j < nums.size(); ++j) {
        const int chosenMask = 1 << i | 1 << j;
        if ((mask & chosenMask) == 0)
          dp[op][mask] =
              max(dp[op][mask], op * __gcd(nums[i], nums[j]) +
                                    maxScore(nums, op + 1, mask | chosenMask));
      }

    return dp[op][mask];
  }
};
