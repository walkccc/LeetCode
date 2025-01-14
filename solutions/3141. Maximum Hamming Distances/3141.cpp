class Solution {
 public:
  vector<int> maxHammingDistances(vector<int>& nums, int m) {
    const int kMaxMask = 1 << m;
    vector<int> ans;
    // dp[i] := the maximum hamming distance from i to any number in `nums`
    vector<int> dp(kMaxMask, INT_MIN);

    for (const int num : nums)
      dp[num] = 0;

    for (int bit = 0; bit < m; ++bit) {
      vector<int> newDp(kMaxMask);
      for (int mask = 0; mask < kMaxMask; ++mask)
        newDp[mask] = max(dp[mask], dp[mask ^ (1 << bit)] + 1);
      dp = std::move(newDp);
    }

    for (const int num : nums)
      ans.push_back(dp[num]);

    return ans;
  }
};
