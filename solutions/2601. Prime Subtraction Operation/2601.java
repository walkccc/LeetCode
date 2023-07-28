class Solution {
  public boolean primeSubOperation(int[] nums) {
    final int kMax = 1000;
    final List<Integer> primes = sieveEratosthenes(kMax);

    int prevNum = 0;
    for (int num : nums) {
      // Make nums[i] the smallest as possible and still > nums[i - 1].
      final int i = firstGreaterEqual(primes, num - prevNum);
      if (i > 0)
        num -= primes.get(i - 1);
      if (num <= prevNum)
        return false;
      prevNum = num;
    }

    return true;
  }

  private List<Integer> sieveEratosthenes(int n) {
    List<Integer> primes = new ArrayList<>();
    boolean[] isPrime = new boolean[n];
    Arrays.fill(isPrime, true);
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i * i < n; ++i)
      if (isPrime[i])
        for (int j = i * i; j < n; j += i)
          isPrime[j] = false;
    for (int i = 2; i < n; ++i)
      if (isPrime[i])
        primes.add(i);
    return primes;
  }

  private int firstGreaterEqual(List<Integer> A, int target) {
    int l = 0;
    int r = A.size();
    while (l < r) {
      final int m = (l + r) / 2;
      if (A.get(m) >= target)
        r = m;
      else
        l = m + 1;
    }
    return l;
  }
}
