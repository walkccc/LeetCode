class Solution {
 public:
  int numberOfArrays(string s, int k) {
    constexpr int kMod = 1'000'000'007;
    const int n = s.length();
    // dp[i] := the number of arrays to restore s[i..n) with k
    vector<int> dp(n + 1);
    dp.back() = 1;  // an empty string ""

    for (int i = n - 1; i >= 0; --i) {
      if (s[i] == '0')
        continue;  // a leading zero
      long num = 0;
      for (int j = i; j < n; ++j) {
        num = num * 10 + (s[j] - '0');
        if (num > k)
          break;
        dp[i] = (dp[i] + dp[j + 1]) % kMod;
      }
    }

    return dp[0];
  }
};
