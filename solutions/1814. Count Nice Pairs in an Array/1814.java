class Solution {
  public int countNicePairs(int[] nums) {
    final int kMod = 1_000_000_007;
    long ans = 0;
    Map<Integer, Long> count = new HashMap<>();

    for (final int num : nums)
      count.merge(num - rev(num), 1L, Long::sum);

    for (final long freq : count.values()) {
      ans += freq * (freq - 1) / 2;
      ans %= kMod;
    }

    return (int) ans;
  }

  private int rev(int n) {
    int x = 0;
    while (n > 0) {
      x = x * 10 + (n % 10);
      n /= 10;
    }
    return x;
  }
}
