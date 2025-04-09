class Solution {
 public:
  int countPalindromes(string s) {
    constexpr int kMod = 1'000'000'007;
    constexpr int kPatternSize = 5;
    long ans = 0;

    for (char a = '0'; a <= '9'; ++a)
      for (char b = '0'; b <= '9'; ++b) {
        const vector<char> pattern{a, b, '.', b, a};
        // dp[i] := the number of subsequences of pattern[i..n) in s, where
        // pattern[2] can be any character
        vector<long> dp(kPatternSize + 1);
        dp.back() = 1;
        for (const char c : s)
          for (int i = 0; i < kPatternSize; ++i)
            if (pattern[i] == '.' || pattern[i] == c)
              dp[i] += dp[i + 1];
        ans += dp[0];
        ans %= kMod;
      }

    return ans;
  }
};
