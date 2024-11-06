class Solution {
  public int findGCD(int[] nums) {
    final int mn = Arrays.stream(nums).min().getAsInt();
    final int mx = Arrays.stream(nums).max().getAsInt();
    return gcd(mn, mx);
  }

  private int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
  }
}
