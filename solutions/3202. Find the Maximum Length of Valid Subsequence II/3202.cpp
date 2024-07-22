class Solution {
 public:
  // Similar to 3201. Find the Maximum Length of Valid Subsequence I
  int maximumLength(vector<int>& nums, int k) {
    // dp[i][j] := the maximum length of a valid subsequence, where the last
    // number mod k equal to i and the next desired number mod k equal to j
    vector<vector<int>> dp(k, vector<int>(k));

    // Extend the pattern xyxyxy...xy.
    for (const int x : nums)
      for (int y = 0; y < k; ++y)
        dp[x % k][y] = dp[y][x % k] + 1;

    return accumulate(dp.begin(), dp.end(), 0,
                      [](int acc, const vector<int>& row) {
      return max(acc, ranges::max(row));
    });
  }
};
