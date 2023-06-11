class Solution {
  public boolean hasGroupsSizeX(int[] deck) {
    Map<Integer, Integer> count = new HashMap<>();
    int gcd = 0;

    for (final int d : deck)
      count.merge(d, 1, Integer::sum);

    for (final int value : count.values())
      gcd = __gcd(gcd, value);

    return gcd >= 2;
  }

  private int __gcd(int a, int b) {
    return b > 0 ? __gcd(b, a % b) : a;
  }
}
