class Solution {
  public int maximumPrimeDifference(int[] nums) {
    final int kMax = 100;
    boolean[] isPrime = sieveEratosthenes(kMax + 1);
    int minPrimeIndex = -1;
    int maxPrimeIndex = -1;

    for (int i = 0; i < nums.length; ++i)
      if (isPrime[nums[i]]) {
        if (minPrimeIndex == -1)
          minPrimeIndex = i;
        maxPrimeIndex = i;
      }

    return maxPrimeIndex - minPrimeIndex;
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
};
