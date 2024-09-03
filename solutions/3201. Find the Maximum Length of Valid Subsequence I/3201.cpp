class Solution {
 public:
  int maximumLength(vector<int>& nums) {
    // dp[i][j] := the maximum length of a valid subsequence, where the last
    // number mod 2 equal to i and the next desired number mod 2 equal to j
    vector<vector<int>> dp(2, vector<int>(2));

    // Extend the pattern xyxyxy...xy.
    for (const int x : nums)
      for (int y = 0; y < 2; ++y)
        dp[x % 2][y] = dp[y][x % 2] + 1;

    return accumulate(dp.begin(), dp.end(), 0,
                      [](int acc, const vector<int>& row) {
      return max(acc, ranges::max(row));
    });
  }
};
