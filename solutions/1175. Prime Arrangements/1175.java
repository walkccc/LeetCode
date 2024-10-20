class Solution {
  public int numPrimeArrangements(int n) {
    final int count = countPrimes(n);
    return (int) (factorial(count) * factorial(n - count) % kMod);
  }

  private static final int kMod = 1_000_000_007;

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

  private long factorial(int n) {
    long fact = 1;
    for (int i = 2; i <= n; ++i)
      fact = fact * i % kMod;
    return fact;
  }
}
