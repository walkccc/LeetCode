class Solution {
 public:
  int numPermsDISequence(string s) {
    constexpr int kMod = 1'000'000'007;
    const int n = s.length();
    vector<int> dp(n + 1);

    // when there's only one digit, the # of perms is 1
    for (int j = 0; j <= n; ++j)
      dp[j] = 1;

    for (int i = 1; i <= n; ++i) {
      vector<int> newDp(n + 1);
      if (s[i - 1] == 'I') {  // s[i - 1] == 'I'
        // calculate postfix sum to prevent duplicate calculation
        int postfixsum = 0;
        for (int j = n - i; j >= 0; --j) {
          postfixsum = (postfixsum + dp[j + 1]) % kMod;
          newDp[j] = postfixsum;
        }
      } else {  // s[i - 1] == 'D'
        // calculate prefix sum to prevent duplicate calculation
        int prefix = 0;
        for (int j = 0; j <= n - i; ++j) {
          prefix = (prefix + dp[j]) % kMod;
          newDp[j] = prefix;
        }
      }
      dp = move(newDp);
    }

    return dp[0];
  }
};
