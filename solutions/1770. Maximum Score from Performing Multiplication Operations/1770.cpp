class Solution {
 public:
  int maximumScore(vector<int>& nums, vector<int>& multipliers) {
    // dp[s][i] := the maximum score of nums[s..e] and multipliers[i]
    dp.resize(multipliers.size(), vector<int>(multipliers.size(), -1));
    return maximumScore(nums, 0, multipliers, 0);
  }

 private:
  vector<vector<int>> dp;

  int maximumScore(const vector<int>& nums, int s,
                   const vector<int>& multipliers, int i) {
    if (i == multipliers.size())
      return 0;
    if (dp[s][i] != -1)
      return dp[s][i];

    // The number of nums picked on the start side is s.
    // The number of nums picked on the end side is i - s.
    // So, e = n - (i - s) - 1.
    const int e = nums.size() - (i - s) - 1;
    const int pickStart = nums[s] * multipliers[i] +
                          maximumScore(nums, s + 1, multipliers, i + 1);
    const int pickEnd = nums[e] * multipliers[i] +  //
                        maximumScore(nums, s, multipliers, i + 1);
    return dp[s][i] = max(pickStart, pickEnd);
  }
};
