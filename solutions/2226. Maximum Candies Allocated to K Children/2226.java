class Solution {
  public int maximumCandies(int[] candies, long k) {
    int l = 1;
    int r = (int) (Arrays.stream(candies).asLongStream().sum() / k);

    while (l < r) {
      final int m = (l + r) / 2;
      if (numChildren(candies, m) < k)
        r = m;
      else
        l = m + 1;
    }

    return numChildren(candies, l) >= k ? l : l - 1;
  }

  private long numChildren(int[] candies, int m) {
    return Arrays.stream(candies).asLongStream().reduce(0L, (subtotal, c) -> subtotal + c / m);
  }
}
