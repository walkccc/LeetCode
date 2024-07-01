class Solution {
  public int findGCD(int[] nums) {
    final int min = Arrays.stream(nums).min().getAsInt();
    final int max = Arrays.stream(nums).max().getAsInt();
    return gcd(min, max);
  }

  private int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
  }
}
