class Solution {
  public int findValidSplit(int[] nums) {
    Map<Integer, Integer> leftPrimeFactors = new HashMap<>();
    Map<Integer, Integer> rightPrimeFactors = new HashMap<>();

    for (final int num : nums)
      for (final int primeFactor : getPrimeFactors(num))
        rightPrimeFactors.merge(primeFactor, 1, Integer::sum);

    for (int i = 0; i < nums.length - 1; ++i) {
      for (final int primeFactor : getPrimeFactors(nums[i])) {
        rightPrimeFactors.merge(primeFactor, -1, Integer::sum);
        if (rightPrimeFactors.get(primeFactor) == 0) {
          // rightPrimeFactors[primeFactor] == 0, so no need to track
          // leftPrimeFactors[primeFactor].
          rightPrimeFactors.remove(primeFactor);
          leftPrimeFactors.remove(primeFactor);
        } else {
          // Otherwise, need to track leftPrimeFactors[primeFactor].
          leftPrimeFactors.merge(primeFactor, 1, Integer::sum);
        }
      }
      if (leftPrimeFactors.isEmpty())
        return i;
    }

    return -1;
  }

  // Gets the prime factors under sqrt(10^6).
  private List<Integer> getPrimeFactors(int num) {
    List<Integer> primeFactors = new ArrayList<>();
    for (int divisor = 2; divisor <= Math.min(1000, num); ++divisor)
      if (num % divisor == 0) {
        primeFactors.add(divisor);
        while (num % divisor == 0)
          num /= divisor;
      }
    // Handle the case that `num` contains a prime factor > 1000.
    if (num > 1)
      primeFactors.add(num);
    return primeFactors;
  }
}
