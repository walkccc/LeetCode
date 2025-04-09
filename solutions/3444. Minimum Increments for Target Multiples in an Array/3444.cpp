class Solution {
 public:
  int minimumIncrements(vector<int>& nums, vector<int>& target) {
    const int maxMask = 1 << target.size();
    unordered_map<int, long> maskToLcm;

    for (int mask = 1; mask < maxMask; ++mask) {
      const vector<int> subset = getSubset(mask, target);
      maskToLcm[mask] = getLcm(subset);
    }

    // dp[mask] := the minimum number of increments to make each number in the
    // subset of target have at least one number that is a multiple in `num`,
    // where `mask` is the bitmask of the subset of target
    vector<long> dp(maxMask, LONG_MAX);
    dp[0] = 0;

    for (const int num : nums) {
      // maskToCost := (mask, cost), where `mask` is the bitmask of the subset
      // of target and `cost` is the minimum number of increments to make each
      // number in the subset of target have at least one number that is a
      // multiple in `num`
      vector<pair<int, long>> maskToCost;
      for (const auto& [mask, lcm] : maskToLcm) {
        const int remainder = num % lcm;
        maskToCost.emplace_back(mask, remainder == 0 ? 0 : lcm - remainder);
      }
      vector<long> newDp = dp;
      for (int prevMask = 0; prevMask < maxMask; ++prevMask) {
        if (dp[prevMask] == LONG_MAX)
          continue;
        for (const auto& [mask, cost] : maskToCost) {
          const int nextMask = prevMask | mask;
          newDp[nextMask] = min(newDp[nextMask], dp[prevMask] + cost);
        }
      }
      dp = std::move(newDp);
    }

    return dp.back() == LONG_MAX ? -1 : dp.back();
  }

 private:
  vector<int> getSubset(int mask, const vector<int>& target) {
    vector<int> subset;
    for (int i = 0; i < target.size(); ++i)
      if (mask >> i & 1)
        subset.push_back(target[i]);
    return subset;
  }

  long getLcm(const vector<int>& nums) {
    long res = 1;
    for (const int num : nums)
      res = lcm(res, num);
    return res;
  }
};
