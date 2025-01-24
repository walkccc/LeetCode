class Solution {
  // Similar to 53. Maximum Subarray
  public int maximumSum(int[] arr) {
    final int kMin = Integer.MIN_VALUE / 2;
    int ans = kMin;
    int zero = kMin; // no deletion
    int one = kMin;  // <= 1 deletion

    for (final int a : arr) {
      one = Math.max(a, Math.max(one + a, zero /*delete a*/));
      zero = Math.max(a, zero + a);
      ans = Math.max(ans, one);
    }

    return ans;
  }
}
