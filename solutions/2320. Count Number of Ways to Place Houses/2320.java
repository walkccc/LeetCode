class Solution {
  public int countHousePlacements(int n) {
    final int MOD = 1_000_000_007;
    int house = 1; // the number of ways ending in a house
    int space = 1; // the number of ways ending in a space
    int total = house + space;

    for (int i = 2; i <= n; ++i) {
      house = space;
      space = total;
      total = (house + space) % MOD;
    }

    return (int) ((long) total * total % MOD);
  }
}
