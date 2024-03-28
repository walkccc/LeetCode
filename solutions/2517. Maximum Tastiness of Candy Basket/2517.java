class Solution {
  public int maximumTastiness(int[] price, int k) {
    Arrays.sort(price);

    int l = 0;
    int r = Arrays.stream(price).max().getAsInt() - Arrays.stream(price).min().getAsInt() + 1;

    while (l < r) {
      final int m = (l + r) / 2;
      if (numBaskets(price, m) >= k)
        l = m + 1;
      else
        r = m;
    }

    return l - 1;
  }

  // Returns the number of baskets we can pick for m tastiness.
  private int numBaskets(int[] price, int m) {
    int baskets = 0;
    int prevPrice = -m;
    for (final int p : price)
      if (p >= prevPrice + m) {
        prevPrice = p;
        ++baskets;
      }
    return baskets;
  }
}
