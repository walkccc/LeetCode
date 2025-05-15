class Solution {
 public:
  vector<long long> resultArray(vector<int>& nums, int k) {
    vector<long long> ans(k);
    // dp[r] := the number of subarrays ending at current position with
    // product % k == r
    vector<long long> dp(k);

    for (const int num : nums) {
      vector<long long> newDp(k);
      const int numMod = num % k;
      // Start new subarray with only `num`.
      newDp[numMod] = 1;
      // Extend all previous subarrays.
      for (int i = 0; i < k; ++i) {
        const int newMod = (static_cast<long>(i) * numMod) % k;
        newDp[newMod] += dp[i];
      }
      // Accumulate counts into ans.
      for (int i = 0; i < k; ++i)
        ans[i] += newDp[i];
      dp = std::move(newDp);
    }

    return ans;
  }
};
