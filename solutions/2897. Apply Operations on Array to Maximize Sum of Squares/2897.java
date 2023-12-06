class Solution {
  public int maxSum(List<Integer> nums, int k) {
    final int kMod = 1_000_000_007;
    final int kMaxBit = 30;
    int ans = 0;
    // minIndices[i] := the minimum index in the `optimalNums` that the i-th bit should be moved to
    int[] minIndices = new int[kMaxBit];
    int[] optimalNums = new int[nums.size()];

    for (final int num : nums)
      for (int i = 0; i < kMaxBit; i++)
        if ((num >> i & 1) == 1)
          optimalNums[minIndices[i]++] |= 1 << i;

    for (int i = 0; i < k; i++)
      ans = (int) (((long) ans + (long) optimalNums[i] * optimalNums[i]) % kMod);

    return ans;
  }
}
