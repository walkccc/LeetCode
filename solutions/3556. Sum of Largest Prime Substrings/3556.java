class Solution {
  public long sumOfLargestPrimes(String s) {
    final int n = s.length();
    Set<Long> primes = new HashSet<>();

    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j <= n; ++j) {
        final long num = Long.parseLong(s.substring(i, j));
        if (!primes.contains(num) && isPrime(num))
          primes.add(num);
      }

    List<Long> sortedPrimes = new ArrayList<>(primes);
    Collections.sort(sortedPrimes, Collections.reverseOrder());
    return sortedPrimes.stream().limit(3).mapToLong(Long::longValue).sum();
  }

  private boolean isPrime(long num) {
    if (num <= 1)
      return false;
    for (int i = 2; i <= Math.sqrt(num); i++)
      if (num % i == 0)
        return false;
    return true;
  }
}
