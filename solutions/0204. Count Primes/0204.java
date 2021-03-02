class Solution {
  public int countPrimes(int n) {
    if (n <= 2)
      return 0;

    int ans = 0;
    boolean[] prime = new boolean[n];
    Arrays.fill(prime, 2, n, true);

    for (int i = 0; i < Math.sqrt(n); ++i)
      if (prime[i])
        for (int j = i * i; j < n; j += i)
          prime[j] = false;

    for (final boolean p : prime)
      if (p)
        ++ans;

    return ans;
  }
}
