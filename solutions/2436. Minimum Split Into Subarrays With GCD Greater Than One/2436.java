class Solution {
  public int minimumSplits(int[] nums) {
    int ans = 1;
    int gcd = nums[0];

    for (final int num : nums) {
      final int newGcd = gcd(gcd, num);
      if (newGcd > 1) {
        gcd = newGcd;
      } else {
        gcd = num;
        ++ans;
      }
    }

    return ans;
  }

  private int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
  }
}
