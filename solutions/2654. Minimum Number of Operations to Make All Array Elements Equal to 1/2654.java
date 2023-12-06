class Solution {
  public int minOperations(int[] nums) {
    final int n = nums.length;
    final int ones = (int) Arrays.stream(nums).filter(num -> num == 1).count();
    if (ones > 0)
      return n - ones;

    // the minimum operations to make the shortest subarray with a gcd == 1
    int minOps = Integer.MAX_VALUE;

    for (int i = 0; i < n; ++i) {
      int g = nums[i];
      for (int j = i + 1; j < n; ++j) {
        g = gcd(g, nums[j]);
        if (g == 1) { // gcd(nums[i..j]) == 1
          minOps = Math.min(minOps, j - i);
          break;
        }
      }
    }

    // After making the shortest subarray with the `minOps`, need additional
    // n - 1 operations to make the other numbers to 1.
    return minOps == Integer.MAX_VALUE ? -1 : minOps + n - 1;
  }

  private int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
  }
}
