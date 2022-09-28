class Solution {
  public int maximumANDSum(int[] nums, int numSlots) {
    final int n = 2 * numSlots;
    final int nSelected = 1 << n;
    // dp[i] := max value given mask representing the nums selected
    int[] dp = new int[nSelected];
    int[] A = Arrays.copyOf(nums, n);

    for (int mask = 1; mask < nSelected; ++mask) {
      final int selected = Integer.bitCount(mask);
      final int slot = (selected + 1) / 2; // (1, 2) -> 1, (3, 4) -> 2
      for (int i = 0; i < n; ++i)
        if ((mask >> i & 1) == 1) // assign A[i] to `slot`-th slot
          dp[mask] = Math.max(dp[mask], dp[mask ^ 1 << i] + (slot & A[i]));
    }

    return dp[nSelected - 1];
  }
}
