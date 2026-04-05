class Solution {
  public int countOrders(int n) {
    final int MOD = 1_000_000_007;
    long ans = 1;

    for (int i = 1; i <= n; ++i)
      ans = ans * i * (i * 2 - 1) % MOD;

    return (int) ans;
  }
}
