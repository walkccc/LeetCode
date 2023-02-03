class Solution {
  public int maximumTastiness(int[] price, int k) {
    int l = 0;
    int r = Arrays.stream(price).max().getAsInt() - Arrays.stream(price).min().getAsInt() + 1;

    Arrays.sort(price);

    while (l < r) {
      final int m = (l + r) / 2;
      if (maxSize(price, m) >= k)
        l = m + 1;
      else
        r = m;
    }

    return l - 1;
  }

  // Returns the max size basket of m tastiness.
  private int maxSize(int[] price, int m) {
    int size = 0;
    int prevPrice = -m;
    for (final int p : price)
      if (p >= prevPrice + m) {
        prevPrice = p;
        ++size;
      }
    return size;
  }
}
