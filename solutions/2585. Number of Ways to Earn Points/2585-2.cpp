class Solution {
 public:
  int waysToReachTarget(int target, vector<vector<int>>& types) {
    constexpr int kMod = 1'000'000'007;
    // dp[j] := the number of ways to earn j points with the types so far
    vector<int> dp(target + 1);
    dp[0] = 1;

    for (const vector<int>& type : types) {
      const int count = type[0];
      const int mark = type[1];
      for (int j = target; j >= 0; --j)
        for (int solved = 1; solved <= count; ++solved)
          if (j - solved * mark >= 0) {
            dp[j] += dp[j - solved * mark];
            dp[j] %= kMod;
          }
    }

    return dp[target];
  }
};
