class Solution {
  public int beautifulPartitions(String s, int k, int minLength) {
    if (!isPrime(s.charAt(0)) || isPrime(s.charAt(s.length() - 1)))
      return 0;

    this.minLength = minLength;
    // dp[i][k] := the number of beautiful partitions of s[i..n) with k bars (|)
    // left
    dp = new Integer[s.length()][k];
    return partitions(s, minLength, k - 1);
  }

  private static final int kMod = 1_000_000_007;
  private int minLength;
  private Integer[][] dp;

  private int partitions(final String s, int i, int k) {
    if (i <= s.length() && k == 0)
      return 1;
    if (i >= s.length())
      return 0;
    if (dp[i][k] != null)
      return dp[i][k];

    // Don't split between s[i - 1] and s[i].
    int ans = partitions(s, i + 1, k) % kMod;

    // Split between s[i - 1] and s[i].
    if (isPrime(s.charAt(i)) && !isPrime(s.charAt(i - 1)))
      ans += partitions(s, i + minLength, k - 1);

    return dp[i][k] = ans % kMod;
  }

  private boolean isPrime(char c) {
    return c == '2' || c == '3' || c == '5' || c == '7';
  }
}
