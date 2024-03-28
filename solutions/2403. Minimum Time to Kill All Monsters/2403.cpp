class Solution {
 public:
  long long minimumTime(vector<int>& power) {
    const int n = power.size();
    const int maxMask = 1 << n;
    // dp[i] := the minimum number of days needed to defeat the monsters, where
    // i is the bitmask of the monsters
    vector<long> dp(maxMask, LONG_MAX);
    dp[0] = 0;

    for (int mask = 1; mask < maxMask; ++mask) {
      const int currentGain = __builtin_popcount(mask);
      for (int i = 0; i < n; ++i)
        if (mask >> i & 1)
          dp[mask] =
              min(dp[mask],
                  dp[mask & ~(1 << i)] +
                      static_cast<int>(ceil(power[i] * 1.0 / currentGain)));
    }

    return dp.back();
  }
};
