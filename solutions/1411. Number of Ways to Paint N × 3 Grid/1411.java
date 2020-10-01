class Solution {
  public int numOfWays(int n) {
    final long kMod = (long) 1e9 + 7;

    long color2 = 6; // pattern 121
    long color3 = 6; // pattern 123

    for (int i = 1; i < n; ++i) {
      final long nextColor2 = color2 * 3 + color3 * 2;
      final long nextColor3 = color2 * 2 + color3 * 2;
      color2 = nextColor2 % kMod;
      color3 = nextColor3 % kMod;
    }

    return (int) ((color2 + color3) % kMod);
  }
}