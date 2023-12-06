class Solution {
  public int minimumIncompatibility(int[] nums, int k) {
    final int kMaxCompatibility = (16 - 1) * (16 / 2);
    final int n = nums.length;
    final int subsetSize = n / k;
    final int maxMask = 1 << n;
    final int[] incompatibilities = getIncompatibilities(nums, subsetSize);
    // dp[i] := the minimum possible sum of incompatibilities of the subset
    // of numbers represented by the bitmask i
    int[] dp = new int[maxMask];
    Arrays.fill(dp, kMaxCompatibility);
    dp[0] = 0;

    for (int mask = 1; mask < maxMask; ++mask) {
      // The number of 1s in `mask` isn't a multiple of `subsetSize`.
      if (Integer.bitCount(mask) % subsetSize != 0)
        continue;
      // https://cp-algorithms.com/algebra/all-submasks.html
      for (int submask = mask; submask > 0; submask = (submask - 1) & mask)
        if (incompatibilities[submask] != -1) // valid submask
          dp[mask] = Math.min(dp[mask], dp[mask - submask] + incompatibilities[submask]);
    }

    return dp[maxMask - 1] == kMaxCompatibility ? -1 : dp[maxMask - 1];
  }

  private static final int kMaxNum = 16;

  // Returns an incompatibilities array where
  // * incompatibilities[i] := the incompatibility of the subset of numbers
  //   represented by the bitmask i
  // * incompatibilities[i] := -1 if the number of 1s in the bitmask i is not
  //   `subsetSize`
  private int[] getIncompatibilities(int[] nums, int subsetSize) {
    final int maxMask = 1 << nums.length;
    int[] incompatibilities = new int[maxMask];
    Arrays.fill(incompatibilities, -1);
    for (int mask = 0; mask < maxMask; ++mask)
      if (Integer.bitCount(mask) == subsetSize && isUnique(nums, mask, subsetSize))
        incompatibilities[mask] = getIncompatibility(nums, mask);
    return incompatibilities;
  }

  // Returns true if the numbers selected by the `mask` are unique.
  //
  // e.g. If we call isUnique(0b1010, 2, [1, 2, 1, 4]), the `used` variable
  // will be 0b1, which only has one 1 (less than `subsetSize`). In this case,
  // we should return false.
  private boolean isUnique(int[] nums, int mask, int subsetSize) {
    int used = 0;
    for (int i = 0; i < nums.length; ++i)
      if ((mask >> i & 1) == 1)
        used |= 1 << nums[i];
    return Integer.bitCount(used) == subsetSize;
  }

  // Returns the incompatibility of the selected numbers represented by the
  // `mask`.
  private int getIncompatibility(int[] nums, int mask) {
    int mini = kMaxNum;
    int maxi = 0;
    for (int i = 0; i < nums.length; ++i)
      if ((mask >> i & 1) == 1) {
        maxi = Math.max(maxi, nums[i]);
        mini = Math.min(mini, nums[i]);
      }
    return maxi - mini;
  }
}
