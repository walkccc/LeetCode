class Solution {
  public int superPow(int a, int[] b) {
    int ans = 1;

    a %= MOD;
    for (final int i : b)
      ans = modPow(ans, 10) * modPow(a, i) % MOD;

    return ans;
  }

  private static final int MOD = 1337;

  private int modPow(int x, int n) {
    if (n == 0)
      return 1;
    if (n % 2 == 1)
      return x * modPow(x % MOD, (n - 1)) % MOD;
    return modPow(x * x % MOD, (n / 2)) % MOD;
  }
}
