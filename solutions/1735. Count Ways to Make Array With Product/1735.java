class Solution {
  public int[] waysToFillArray(int[][] queries) {
    final int kMax = 10_000;
    final int kMaxFreq = 13; // 2^13 = 8192 < kMax
    final int[] minPrimeFactors = sieveEratosthenes(kMax + 1);
    final long[][] factAndInvFact = getFactAndInvFact(kMax + kMaxFreq - 1);
    final long[] fact = factAndInvFact[0];
    final long[] invFact = factAndInvFact[1];
    int[] ans = new int[queries.length];

    for (int i = 0; i < queries.length; ++i) {
      final int n = queries[i][0];
      final int k = queries[i][1];
      int res = 1;
      for (final int freq : getPrimeFactorsCount(k, minPrimeFactors).values())
        res = (int) ((long) res * nCk(n - 1 + freq, freq, fact, invFact) % kMod);
      ans[i] = res;
    }

    return ans;
  }

  private static final int kMod = 1_000_000_007;

  // Gets the minimum prime factor of i, where 1 < i <= n.
  private int[] sieveEratosthenes(int n) {
    int[] minPrimeFactors = new int[n + 1];
    for (int i = 2; i <= n; ++i)
      minPrimeFactors[i] = i;
    for (int i = 2; i * i < n; ++i)
      if (minPrimeFactors[i] == i) // `i` is prime.
        for (int j = i * i; j < n; j += i)
          minPrimeFactors[j] = Math.min(minPrimeFactors[j], i);
    return minPrimeFactors;
  }

  private Map<Integer, Integer> getPrimeFactorsCount(int num, int[] minPrimeFactors) {
    Map<Integer, Integer> count = new HashMap<>();
    while (num > 1) {
      final int divisor = minPrimeFactors[num];
      while (num % divisor == 0) {
        num /= divisor;
        count.put(divisor, count.merge(divisor, 1, Integer::sum));
      }
    }
    return count;
  }

  private long[][] getFactAndInvFact(int n) {
    long[] fact = new long[n + 1];
    long[] invFact = new long[n + 1];
    long[] inv = new long[n + 1];
    fact[0] = invFact[0] = 1;
    inv[0] = inv[1] = 1;
    for (int i = 1; i <= n; ++i) {
      if (i >= 2)
        inv[i] = kMod - kMod / i * inv[kMod % i] % kMod;
      fact[i] = fact[i - 1] * i % kMod;
      invFact[i] = invFact[i - 1] * inv[i] % kMod;
    }
    return new long[][] {fact, invFact};
  }

  private int nCk(int n, int k, long[] fact, long[] invFact) {
    return (int) (fact[n] * invFact[k] % kMod * invFact[n - k] % kMod);
  }
}
