class Solution {
 public:
  int maximumANDSum(vector<int>& nums, int numSlots) {
    const int n = 2 * numSlots;
    const int nSelected = 1 << n;
    // dp[i] := max value given mask representing the nums selected
    vector<int> dp(nSelected);

    nums.resize(n);

    for (int mask = 1; mask < nSelected; ++mask) {
      const int selected = __builtin_popcount(mask);
      const int slot = (selected + 1) / 2;  // (1, 2) -> 1, (3, 4) -> 2
      for (int i = 0; i < n; ++i)
        if (mask >> i & 1)  // assign nums[i] to `slot`-th slot
          dp[mask] = max(dp[mask], dp[mask ^ 1 << i] + (slot & nums[i]));
    }

    return dp.back();
  }
};
