class Solution {
  public int numSubseq(int[] nums, int target) {
    final int MOD = 1_000_000_007;
    final int n = nums.length;
    int ans = 0;
    int[] pows = new int[n]; // pows[i] = 2^i % MOD
    pows[0] = 1;

    for (int i = 1; i < n; ++i)
      pows[i] = pows[i - 1] * 2 % MOD;

    Arrays.sort(nums);

    for (int l = 0, r = n - 1; l <= r;)
      if (nums[l] + nums[r] <= target) {
        ans += pows[r - l];
        ans %= MOD;
        ++l;
      } else {
        --r;
      }

    return ans;
  }
}
