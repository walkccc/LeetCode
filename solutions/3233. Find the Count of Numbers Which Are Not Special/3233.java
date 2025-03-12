class Solution {
  public int nonSpecialCount(int l, int r) {
    final int maxRoot = (int) Math.sqrt(r);
    final boolean[] isPrime = sieveEratosthenes(maxRoot + 1);
    int specialCount = 0;

    for (int num = 2; num <= Math.sqrt(r); ++num)
      if (isPrime[num] && l <= num * num && num * num <= r)
        ++specialCount;

    return r - l + 1 - specialCount;
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
