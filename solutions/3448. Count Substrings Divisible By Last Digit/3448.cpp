class Solution {
 public:
  long long countSubstrings(string s) {
    long ans = 0;
    // dp[i][num][rem] := the number of first `i` digits of s that have a
    // remainder of `rem` when divided by `num`
    vector<vector<vector<int>>> dp(s.length() + 1,
                                   vector<vector<int>>(10, vector<int>(10)));

    for (int i = 1; i <= s.length(); ++i) {
      const int digit = s[i - 1] - '0';
      for (int num = 1; num < 10; ++num) {
        for (int rem = 0; rem < num; ++rem)
          dp[i][num][(rem * 10 + digit) % num] += dp[i - 1][num][rem];
        ++dp[i][num][digit % num];
      }
      ans += dp[i][digit][0];
    }

    return ans;
  }
};
