class Solution {
  public int maximumXorProduct(long a, long b, int n) {
    final int kMod = 1_000_000_007;
    if (n > 0)
      for (long bit = 1L << (n - 1); bit > 0; bit >>= 1)
        // Pick a bit if it makes Math.min(a, b) larger.
        if ((Math.min(a, b) & bit) == 0) {
          a ^= bit;
          b ^= bit;
        }
    return (int) (a % kMod * (b % kMod) % kMod);
  }
}
