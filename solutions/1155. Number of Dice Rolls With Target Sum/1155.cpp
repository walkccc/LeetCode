class Solution {
 public:
  int numRollsToTarget(int d, int f, int target) {
    const int kMod = 1e9 + 7;
    vector<int> dp(target + 1);
    dp[0] = 1;

    while (d--) {  // d dices
      vector<int> newDp(target + 1);
      for (int i = 1; i <= f; ++i)         // number 1, 2, ..., f
        for (int t = i; t <= target; ++t)  // possible targets
          newDp[t] = (newDp[t] + dp[t - i]) % kMod;
      swap(dp, newDp);
    }

    return dp[target];
  }
};
