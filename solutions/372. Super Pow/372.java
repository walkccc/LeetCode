class Solution {
  public int superPow(int a, int[] b) {
    int ans = 1;

    a %= kMod;
    for (final int i : b)
      ans = modPow(ans, 10) * modPow(a, i) % kMod;

    return ans;
  }

  private static final int kMod = 1337;

  private int modPow(int x, int n) {
    if (n == 0)
      return 1;
    if (n % 2 == 1)
      return x * modPow(x % kMod, (n - 1)) % kMod;
    return modPow(x * x % kMod, (n / 2)) % kMod;
  }
}
