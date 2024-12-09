class Solution {
  public int countRoutes(int[] locations, int start, int finish, int fuel) {
    Integer[][] mem = new Integer[locations.length][fuel + 1];
    return countRoutes(locations, start, finish, fuel, mem);
  }

  private static final int kMod = 1_000_000_007;

  // Returns the number of ways to reach the `finish` city from the i-th city
  // with `fuel` fuel.
  private int countRoutes(int[] locations, int i, int finish, int fuel, Integer[][] mem) {
    if (fuel < 0)
      return 0;
    if (mem[i][fuel] != null)
      return mem[i][fuel];

    int res = (i == finish) ? 1 : 0;
    for (int j = 0; j < locations.length; ++j) {
      if (j == i)
        continue;
      res += countRoutes(locations, j, finish, fuel - Math.abs(locations[i] - locations[j]), mem);
      res %= kMod;
    }

    return mem[i][fuel] = res;
  }
}
