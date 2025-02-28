class Solution {
  public int beautifulPartitions(String s, int k, int minLength) {
    if (!isPrime(s.charAt(0)) || isPrime(s.charAt(s.length() - 1)))
      return 0;
    Integer[][] mem = new Integer[s.length()][k];
    return beautifulPartitions(s, minLength, k - 1, minLength, mem);
  }

  private static final int kMod = 1_000_000_007;

  // Returns the number of beautiful partitions of s[i..n) with k bars (|) left.
  private int beautifulPartitions(final String s, int i, int k, int minLength, Integer[][] mem) {
    if (i <= s.length() && k == 0)
      return 1;
    if (i >= s.length())
      return 0;
    if (mem[i][k] != null)
      return mem[i][k];

    // Don't split between s[i - 1] and s[i].
    int ans = beautifulPartitions(s, i + 1, k, minLength, mem) % kMod;

    // Split between s[i - 1] and s[i].
    if (isPrime(s.charAt(i)) && !isPrime(s.charAt(i - 1)))
      ans += beautifulPartitions(s, i + minLength, k - 1, minLength, mem);

    return mem[i][k] = ans % kMod;
  }

  private boolean isPrime(char c) {
    return c == '2' || c == '3' || c == '5' || c == '7';
  }
}
