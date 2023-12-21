class Solution {
  public int minEatingSpeed(int[] piles, int h) {
    int l = 1;
    int r = Arrays.stream(piles).max().getAsInt();

    while (l < r) {
      final int m = (l + r) / 2;
      if (eatHours(piles, m) <= h)
        r = m;
      else
        l = m + 1;
    }

    return l;
  }

  // Returns the hours to eat all the piles with speed m.
  private int eatHours(int[] piles, int m) {
    return Arrays.stream(piles).reduce(
        0, (subtotal, pile) -> subtotal + (pile - 1) / m + 1); // Math.ceil(pile / m)
  }
}
