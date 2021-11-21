class Solution {
  public int minEatingSpeed(int[] piles, int h) {
    int l = 1;
    int r = Arrays.stream(piles).max().getAsInt();

    while (l < r) {
      final int m = l + (r - l) / 2;
      if (eatHours(piles, m) <= h)
        r = m;
      else
        l = m + 1;
    }

    return l;
  }

  // hours to eat all piles with speed k
  private int eatHours(int[] piles, int k) {
    int hours = 0;
    for (final int pile : piles)
      hours += (pile - 1) / k + 1; // Math.ceil(pile / k)
    return hours;
  }
}
