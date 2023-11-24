class Solution {
 public:
  int numberOfWays(int numPeople) {
    constexpr int kMod = 1'000'000'007;
    // dp[i] := # of ways i handshakes pair w/o crossing
    vector<long> dp(numPeople / 2 + 1);
    dp[0] = 1;

    for (int i = 1; i <= numPeople / 2; ++i)
      for (int j = 0; j < i; ++j) {
        dp[i] += dp[j] * dp[i - 1 - j];
        dp[i] %= kMod;
      }

    return dp[numPeople / 2];
  }
};
