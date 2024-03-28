class Solution {
  public int countDistinctStrings(String s, int k) {
    // Since the content of `s` doesn't matter, for each i in [0, n - k], we can
    // flip s[i..i + k] or don't flip it. Therefore, there's 2^(n - k + 1) ways.
    return (int) modPow(2, s.length() - k + 1);
  }

  private static final int kMod = 1_000_000_007;

  private long modPow(long x, long n) {
    if (n == 0)
      return 1;
    if (n % 2 == 1)
      return x * modPow(x, n - 1) % kMod;
    return modPow(x * x % kMod, n / 2);
  }
}
