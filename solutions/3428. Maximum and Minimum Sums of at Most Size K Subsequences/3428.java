class Solution {
  public int minMaxSums(int[] nums, int k) {
    // In a sorted array, nums[i] will be
    //   1. The maximum for subsequences formed by nums[0..i].
    //   2. The minimum for subsequences formed by nums[i..n - 1].
    //
    // The number of times nums[i] is the maximum is the same as the number of
    // times nums[n - 1 - i] is the minimum, due to the symmetry in subsequences
    // derived from the sorted order.
    //
    // To calculate the contribution of nums[i], we need to find the number of
    // ways to select at most (k - 1) elements from the range of indices where
    // nums[i] is the smallest or nums[n - 1 - i] is the largest.
    final int n = nums.length;
    final int[][] comb = getComb(n, k - 1);
    long ans = 0;

    Arrays.sort(nums);

    // i: available numbers from the left of nums[i] or
    //    available numbers from the right of nums[n - 1 - i]
    for (int i = 0; i < n; ++i) {
      int count = 0;
      for (int j = 0; j <= k - 1; ++j) // selected numbers
        count = (count + comb[i][j]) % MOD;
      ans += (long) nums[i] * count;
      ans += (long) nums[n - 1 - i] * count;
      ans %= MOD;
    }

    return (int) ans;
  }

  private static final int MOD = 1_000_000_007;

  // C(n, k) = C(n - 1, k) + C(n - 1, k - 1)
  private int[][] getComb(int n, int k) {
    int[][] comb = new int[n + 1][k + 1];
    for (int i = 0; i <= n; ++i)
      comb[i][0] = 1;
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= k; ++j)
        comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD;
    return comb;
  }
}
