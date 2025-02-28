class Solution {
 public:
  long long countSubstrings(string s) {
    long ans = 0;
    // dp[num][rem] := the number of substrings so far that have a remainder of
    // `rem` when divided by `num`
    vector<vector<int>> dp(10, vector<int>(10));

    for (const char c : s) {
      const int digit = c - '0';
      vector<vector<int>> newDp(10, vector<int>(10));
      for (int num = 1; num < 10; ++num) {
        for (int rem = 0; rem < num; ++rem)
          newDp[num][(rem * 10 + digit) % num] += dp[num][rem];
        ++newDp[num][digit % num];
      }
      dp = std::move(newDp);
      ans += dp[digit][0];
    }

    return ans;
  }
};
