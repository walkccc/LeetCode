class Solution {
 public:
  int minimumIncompatibility(vector<int>& nums, int k) {
    constexpr int kMaxCompatibility = (16 - 1) * (16 / 2);
    const int n = nums.size();
    const int subsetSize = n / k;
    const int maxMask = 1 << n;
    const vector<int> incompatibilities =
        getIncompatibilities(nums, subsetSize);
    // dp[i] := the minimum possible sum of incompatibilities of the subset
    // of numbers represented by the bitmask i
    vector<int> dp(maxMask, kMaxCompatibility);
    dp[0] = 0;

    for (int mask = 1; mask < maxMask; ++mask) {
      // The number of 1s in `mask` isn't a multiple of `subsetSize`.
      if (__builtin_popcount(mask) % subsetSize != 0)
        continue;
      // https://cp-algorithms.com/algebra/all-submasks.html
      for (int submask = mask; submask > 0; submask = (submask - 1) & mask)
        if (incompatibilities[submask] != -1)  // valid subset
          dp[mask] =
              min(dp[mask], dp[mask - submask] + incompatibilities[submask]);
    }

    return dp.back() == kMaxCompatibility ? -1 : dp.back();
  }

 private:
  static constexpr int kMaxNum = 16;

  // Returns an incompatibilities array where
  // * incompatibilities[i] := the incompatibility of the subset of numbers
  //   represented by the bitmask i
  // * incompatibilities[i] := -1 if the number of 1s in the bitmask i is not
  //   `subsetSize`
  vector<int> getIncompatibilities(const vector<int>& nums, int subsetSize) {
    const int maxMask = 1 << nums.size();
    vector<int> incompatibilities(maxMask, -1);
    for (int mask = 0; mask < maxMask; ++mask)
      if (__builtin_popcount(mask) == subsetSize &&
          isUnique(nums, mask, subsetSize))
        incompatibilities[mask] = getIncompatibility(nums, mask);
    return incompatibilities;
  }

  // Returns true if the numbers selected by the `mask` are unique.
  //
  // e.g. If we call isUnique(0b1010, 2, [1, 2, 1, 4]), the `used` variable
  // will be 0b1, which only has one 1 (less than `subsetSize`). In this case,
  // we should return false.
  bool isUnique(const vector<int>& nums, int mask, int subsetSize) {
    int used = 0;
    for (int i = 0; i < nums.size(); ++i)
      if (mask >> i & 1)
        used |= 1 << nums[i];
    return __builtin_popcount(used) == subsetSize;
  }

  // Returns the incompatibility of the selected numbers represented by the
  // `mask`.
  int getIncompatibility(const vector<int>& nums, int mask) {
    int mini = kMaxNum;
    int maxi = 0;
    for (int i = 0; i < nums.size(); ++i)
      if (mask >> i & 1) {
        maxi = max(maxi, nums[i]);
        mini = min(mini, nums[i]);
      }
    return maxi - mini;
  }
};
