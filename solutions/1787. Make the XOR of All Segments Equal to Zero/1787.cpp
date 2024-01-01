class Solution {
 public:
  int minChanges(vector<int>& nums, int k) {
    constexpr int kMax = 1024;
    const int n = nums.size();
    // counts[i] := the counter that maps at the i-th position
    vector<unordered_map<int, int>> counts(k);
    // dp[i][j] := the minimum number of elements to change s.t. XOR(nums[i..k -
    // 1]) is j
    vector<vector<int>> dp(k, vector<int>(kMax, n));

    for (int i = 0; i < n; ++i)
      ++counts[i % k][nums[i]];

    auto countAt = [n, k](int i) -> int { return n / k + (n % k > i ? 1 : 0); };

    // Initialize the DP array.
    for (int j = 0; j < kMax; ++j)
      dp[k - 1][j] =
          countAt(k - 1) - (counts[k - 1].count(j) ? counts[k - 1][j] : 0);

    for (int i = k - 2; i >= 0; --i) {
      // The worst-case scenario is changing all the i-th position numbers to a
      // non-existent value in the current bucket.
      const int changeAll = countAt(i) + ranges::min(dp[i + 1]);
      for (int j = 0; j < kMax; ++j) {
        dp[i][j] = changeAll;
        for (const auto& [num, freq] : counts[i]) {
          // the cost to change every number in the i-th position to `num`
          const int cost = countAt(i) - freq;
          dp[i][j] = min(dp[i][j], dp[i + 1][j ^ num] + cost);
        }
      }
    }

    return dp[0][0];
  }
};
