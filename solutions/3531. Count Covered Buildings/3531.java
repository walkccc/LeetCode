class Solution {
  public int countCoveredBuildings(int n, int[][] buildings) {
    int ans = 0;
    int[] northernmost = new int[n + 1];
    int[] southernmost = new int[n + 1];
    int[] westernmost = new int[n + 1];
    int[] easternmost = new int[n + 1];
    Arrays.fill(northernmost, Integer.MAX_VALUE);
    Arrays.fill(southernmost, 0);
    Arrays.fill(westernmost, Integer.MAX_VALUE);
    Arrays.fill(easternmost, 0);

    for (int[] building : buildings) {
      final int x = building[0];
      final int y = building[1];
      northernmost[x] = Math.min(northernmost[x], y);
      southernmost[x] = Math.max(southernmost[x], y);
      westernmost[y] = Math.min(westernmost[y], x);
      easternmost[y] = Math.max(easternmost[y], x);
    }

    for (int[] building : buildings) {
      final int x = building[0];
      final int y = building[1];
      if (northernmost[x] < y && y < southernmost[x] //
          && westernmost[y] < x && x < easternmost[y])
        ++ans;
    }

    return ans;
  }
}
