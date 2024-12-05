class Solution {
 public:
  int maxValue(vector<int>& nums, int k) {
    // left[i][j][x] := true if it's possible to get an OR value of x by
    // selecting j numbers from nums[0..i]
    const vector<vector<vector<bool>>> left = getPossibleORs(nums, k);
    // right[i][j][x] := true if it's possible to get an OR value of x by
    // selecting j numbers from nums[i..n - 1]
    vector<vector<vector<bool>>> right =
        getPossibleORs({nums.rbegin(), nums.rend()}, k);
    ranges::reverse(right);

    int ans = 0;

    for (int i = k - 1; i + k < nums.size(); ++i)
      for (int a = 0; a <= kMaxXor; ++a)
        for (int b = 0; b <= kMaxXor; ++b)
          if (left[i][k][a] && right[i + 1][k][b])
            ans = max(ans, a ^ b);

    return ans;
  }

 private:
  static constexpr int kMaxXor = 128;

  // Gets all possible OR values till each index and number of numbers.
  vector<vector<vector<bool>>> getPossibleORs(const vector<int>& nums, int k) {
    // dp[i][j][x] := true if it's possible to get an OR value of x by selecting
    // j numbers from nums[0..i]
    vector<vector<vector<bool>>> dp(
        nums.size(), vector<vector<bool>>(k + 1, vector<bool>(kMaxXor + 1)));

    dp[0][1][nums[0]] = true;

    // No number is selected.
    for (int i = 0; i < nums.size(); ++i)
      dp[i][0][0] = true;

    for (int i = 1; i < nums.size(); ++i)
      for (int j = 1; j <= k; ++j)
        for (int x = 0; x <= kMaxXor; ++x) {
          // 1. Skip the current number.
          if (dp[i - 1][j][x])
            dp[i][j][x] = true;
          // 2. Pick the current number.
          if (dp[i - 1][j - 1][x])
            dp[i][j][nums[i] | x] = true;
        }

    return dp;
  }
};
