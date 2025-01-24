class Solution {
  public List<List<Integer>> findPrimePairs(int n) {
    boolean[] isPrime = sieveEratosthenes(n + 1);
    List<List<Integer>> ans = new ArrayList<>();

    for (int i = 2; i <= n / 2; ++i)
      if (isPrime[i] && isPrime[n - i])
        ans.add(List.of(i, n - i));

    return ans;
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
