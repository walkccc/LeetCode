class Solution {
  public int numberOfGoodSubsets(int[] nums) {
    final int[] primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    final int n = 1 << primes.length;
    final int maxNum = Arrays.stream(nums).max().getAsInt();
    long[] dp = new long[n];
    int[] count = new int[maxNum + 1];

    dp[0] = 1;

    for (final int num : nums)
      ++count[num];

    for (int num = 2; num <= maxNum; ++num) {
      if (count[num] == 0)
        continue;
      if (num % 4 == 0 || num % 9 == 0 || num % 25 == 0)
        continue;
      final int numPrimesMask = getPrimesMask(num, primes);
      for (int primesMask = 0; primesMask < n; ++primesMask) {
        if ((primesMask & numPrimesMask) > 0)
          continue;
        final int nextPrimesMask = primesMask | numPrimesMask;
        dp[nextPrimesMask] += dp[primesMask] * count[num];
        dp[nextPrimesMask] %= kMod;
      }
    }

    return (int) (modPow(2, count[1]) * ((Arrays.stream(dp).sum() - 1) % kMod) % kMod);
  }

  private static final int kMod = 1_000_000_007;

  private int getPrimesMask(int num, int[] primes) {
    int primesMask = 0;
    for (int i = 0; i < primes.length; ++i)
      if (num % primes[i] == 0)
        primesMask |= 1 << i;
    return primesMask;
  }

  private long modPow(long x, long n) {
    if (n == 0)
      return 1;
    if (n % 2 == 1)
      return x * modPow(x, n - 1) % kMod;
    return modPow(x * x % kMod, n / 2);
  }
}
