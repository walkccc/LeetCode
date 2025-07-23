class Solution {
 public:
  int maximumANDSum(vector<int>& nums, int numSlots) {
    const int n = 2 * numSlots;
    const int nSelected = 1 << n;
    // dp[i] := the maximum value, where i is the bitmask of the selected
    // numbers
    vector<int> dp(nSelected);

    nums.resize(n);

    for (unsigned mask = 1; mask < nSelected; ++mask) {
      const int selected = popcount(mask);
      const int slot = (selected + 1) / 2;  // (1, 2) -> 1, (3, 4) -> 2
      for (int i = 0; i < n; ++i)
        if (mask >> i & 1)  // Assign `nums[i]` to the `slot`-th slot.
          dp[mask] = max(dp[mask], dp[mask ^ 1 << i] + (slot & nums[i]));
    }

    return dp.back();
  }
};
