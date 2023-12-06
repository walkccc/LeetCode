class Solution {
  public int countPrimes(int n) {
    if (n <= 2)
      return 0;
    final boolean[] isPrime = sieveEratosthenes(n);
    int ans = 0;
    return (int) IntStream.range(0, isPrime.length)
        .mapToObj(i -> isPrime[i])
        .filter(p -> p)
        .count();
  }

  private boolean[] sieveEratosthenes(int n) {
    boolean[] isPrime = new boolean[n];
    Arrays.fill(isPrime, true);
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i * i < n; ++i)
      if (isPrime[i])
        for (int j = i * i; j < n; j += i)
          isPrime[j] = false;
    return isPrime;
  }
}
