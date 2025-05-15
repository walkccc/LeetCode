class Solution {
  public int countAnagrams(String s) {
    final int n = s.length();
    final long[][] factAndInvFact = getFactAndInvFact(n);
    final long[] fact = factAndInvFact[0];
    final long[] invFact = factAndInvFact[1];
    long ans = 1;

    for (final String word : s.split(" ")) {
      ans = ans * fact[word.length()] % MOD;
      int[] count = new int[26];
      for (final char c : word.toCharArray())
        ++count[c - 'a'];
      for (final int freq : count)
        ans = ans * invFact[freq] % MOD;
    }

    return (int) ans;
  }

  private static final int MOD = 1_000_000_007;

  private long[][] getFactAndInvFact(int n) {
    long[] fact = new long[n + 1];
    long[] invFact = new long[n + 1];
    long[] inv = new long[n + 1];
    fact[0] = invFact[0] = 1;
    inv[0] = inv[1] = 1;
    for (int i = 1; i <= n; ++i) {
      if (i >= 2)
        inv[i] = MOD - MOD / i * inv[MOD % i] % MOD;
      fact[i] = fact[i - 1] * i % MOD;
      invFact[i] = invFact[i - 1] * inv[i] % MOD;
    }
    return new long[][] {fact, invFact};
  }
}
