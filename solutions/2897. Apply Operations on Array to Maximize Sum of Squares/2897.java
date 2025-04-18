class Solution {
  public int maxSum(List<Integer> nums, int k) {
    final int MOD = 1_000_000_007;
    final int MAX_BIT = 30;
    int ans = 0;
    // minIndices[i] := the minimum index in `optimalNums` that the i-th bit
    // should be moved to
    int[] minIndices = new int[MAX_BIT];
    int[] optimalNums = new int[nums.size()];

    for (final int num : nums)
      for (int i = 0; i < MAX_BIT; i++)
        if ((num >> i & 1) == 1)
          optimalNums[minIndices[i]++] |= 1 << i;

    for (int i = 0; i < k; i++)
      ans = (int) ((ans + (long) optimalNums[i] * optimalNums[i]) % MOD);

    return ans;
  }
}
