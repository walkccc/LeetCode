class Solution {
  public int monkeyMove(int n) {
    final int res = (int) myPow(2, n) - 2;
    return res < 0 ? res + kMod : res;
  }

  private static final int kMod = 1_000_000_007;

  private long myPow(long x, int n) {
    if (n == 0)
      return 1;
    if (n % 2 == 1)
      return x * myPow(x, n - 1) % kMod;
    return myPow(x * x % kMod, n / 2);
  }
}
