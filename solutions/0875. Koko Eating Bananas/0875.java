class Solution {
  public int minEatingSpeed(int[] piles, int H) {
    int l = 1;
    int r = Arrays.stream(piles).max().getAsInt();

    while (l < r) {
      final int m = l + (r - l) / 2;
      if (eatHours(piles, m) <= H)
        r = m;
      else
        l = m + 1;
    }

    return l;
  }

  // hours to eat all piles with speed k
  private int eatHours(int[] piles, int k) {
    int hour = 0;
    for (final int pile : piles)
      hour += (pile - 1) / k + 1;
    return hour;
  }
}
