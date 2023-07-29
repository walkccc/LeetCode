class Solution {
  public int numOfWays(int n) {
    final int kMod = 1_000_000_007;
    long color2 = 6; // 121, 131, 212, 232, 313, 323
    long color3 = 6; // 123, 132, 213, 231, 312, 321

    for (int i = 1; i < n; ++i) {
      final long nextColor2 = color2 * 3 + color3 * 2;
      final long nextColor3 = color2 * 2 + color3 * 2;
      color2 = nextColor2 % kMod;
      color3 = nextColor3 % kMod;
    }

    return (int) ((color2 + color3) % kMod);
  }
}
