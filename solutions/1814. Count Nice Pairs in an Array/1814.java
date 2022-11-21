class Solution {
  public int countNicePairs(int[] nums) {
    final int kMod = 1_000_000_007;
    long ans = 0;
    Map<Integer, Long> count = new HashMap<>();

    for (final int num : nums) {
      final int key = num - rev(num);
      count.put(key, count.getOrDefault(key, 0L) + 1);
    }

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
