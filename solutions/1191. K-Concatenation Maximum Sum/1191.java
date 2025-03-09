class Solution {
  public int kConcatenationMaxSum(int[] arr, int k) {
    final int MOD = 1_000_000_007;
    final int sz = arr.length * (k == 1 ? 1 : 2);
    final int sum = Arrays.stream(arr).sum();
    // The concatenated array will be [arr1, arr2, ..., arrk].
    // If sum(arr) > 0 and k > 2, then arr2, ..., arr(k - 1) should be included.
    // Equivalently, maxSubarraySum is from arr1 and arrk.
    if (sum > 0 && k > 2)
      return (int) ((kadane(arr, sz) + sum * (long) (k - 2)) % MOD);
    return kadane(arr, sz) % MOD;
  }

  private int kadane(int[] arr, int sz) {
    int ans = 0;
    int sum = 0;
    for (int i = 0; i < sz; ++i) {
      final int a = arr[i % arr.length];
      sum = Math.max(a, sum + a);
      ans = Math.max(ans, sum);
    }
    return ans;
  }
}
