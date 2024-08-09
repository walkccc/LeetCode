class Solution {
  public int distinctPrimeFactors(int[] nums) {
    Set<Integer> primes = new HashSet<>();

    for (final int num : nums)
      addPrimeFactors(primes, num);

    return primes.size();
  }

  private void addPrimeFactors(Set<Integer> primes, int num) {
    for (int divisor = 2; divisor <= num; ++divisor)
      if (num % divisor == 0) {
        primes.add(divisor);
        while (num % divisor == 0)
          num /= divisor;
      }
  }
}
