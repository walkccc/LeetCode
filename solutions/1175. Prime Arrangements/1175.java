class Solution {
  public int numPrimeArrangements(int n) {
    final int kMod = 1_000_000_007;
    final int count = countPrimes(n);
    return (int) ((factorial(count, kMod) * factorial(n - count, kMod)) % kMod);
  }

  private int countPrimes(int n) {
    boolean[] prime = new boolean[n + 1];
    Arrays.fill(prime, 2, n + 1, true);

    for (int i = 0; i * i <= n; ++i)
      if (prime[i])
        for (int j = i * i; j <= n; j += i)
          prime[j] = false;

    int count = 0;

    for (boolean p : prime)
      if (p)
        ++count;

    return count;
  }

  long factorial(int n, final long kMod) {
    long fact = 1;
    for (int i = 1; i <= n; ++i)
      fact = fact * i % kMod;
    return fact;
  }
}
