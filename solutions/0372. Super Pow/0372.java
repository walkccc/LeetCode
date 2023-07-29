class Solution {
  public int superPow(int a, int[] b) {
    int ans = 1;

    a %= k;
    for (final int i : b)
      ans = powMod(ans, 10) * powMod(a, i) % k;

    return ans;
  }

  private final int k = 1337;

  private int powMod(int x, int y) {
    int pow = 1;
    while (y-- > 0)
      pow = (pow * x) % k;
    return pow;
  }
}
