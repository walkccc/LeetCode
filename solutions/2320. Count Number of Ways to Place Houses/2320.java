class Solution {
  public int countHousePlacements(int n) {
    final int kMod = 1_000_000_007;
    int house = 1; // # of ways ending w/ house
    int space = 1; // # of ways ending w/ space
    int total = house + space;

    for (int i = 2; i <= n; ++i) {
      house = space;
      space = total;
      total = (house + space) % kMod;
    }

    return (int) ((long) total * total % kMod);
  }
}
