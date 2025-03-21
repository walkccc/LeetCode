class Solution {
 public:
  int longestSubsequence(vector<int>& nums) {
    const int mx = ranges::max(nums);
    // dp[num][diff] := the length of the longest subsequence ending in `num`
    // s.t. the last absolute difference between consecutive elements is `diff`
    vector<vector<int>> dp(mx + 1, vector<int>(mx + 1));

    for (const int num : nums) {
      for (int prev = 1; prev <= mx; ++prev) {
        const int diff = abs(num - prev);
        dp[num][diff] = max(dp[num][diff], dp[prev][diff] + 1);
      }
      // dp[num][diff] := max(dp[num][j]), where j >= diff
      for (int j = mx - 1; j >= 0; --j)
        dp[num][j] = max(dp[num][j], dp[num][j + 1]);
    }

    return ranges::max_element(dp, ranges::less{}, [](const vector<int>& row) {
      return row[0];
    })->at(0);
  }
};
