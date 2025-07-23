class Solution {
  public long maximumCoins(int[][] coins, int k) {
    int[][] negatedCoins = negateLeftRight(coins);
    return Math.max(slide(coins, k), slide(negatedCoins, k));
  }

  private int[][] negateLeftRight(int[][] coins) {
    int[][] res = new int[coins.length][3];
    for (int i = 0; i < coins.length; ++i) {
      final int l = coins[i][0];
      final int r = coins[i][1];
      final int c = coins[i][2];
      res[i][0] = -r;
      res[i][1] = -l;
      res[i][2] = c;
    }
    return res;
  }

  private long slide(int[][] coins, int k) {
    long res = 0;
    long windowSum = 0;
    int j = 0;

    Arrays.sort(coins, Comparator.comparingInt((int[] coin) -> coin[0]));

    for (int[] coin : coins) {
      final int li = coin[0];
      final int ri = coin[1];
      final int ci = coin[2];
      final int rightBoundary = li + k;

      // [lj, rj] is fully in [li..li + k).
      while (j + 1 < coins.length && coins[j + 1][0] < rightBoundary) {
        final int lj = coins[j][0];
        final int rj = coins[j][1];
        final int cj = coins[j][2];
        windowSum += (long) (rj - lj + 1) * cj;
        ++j;
      }

      // [lj, rj] may be partially in [l..l + k).
      long last = 0;
      if (j < coins.length && coins[j][0] < rightBoundary) {
        final int lj = coins[j][0];
        final int rj = coins[j][1];
        final int cj = coins[j][2];
        last = (long) (Math.min(rightBoundary - 1, rj) - lj + 1) * cj;
      }

      res = Math.max(res, windowSum + last);
      windowSum -= (long) (ri - li + 1) * ci;
    }

    return res;
  }
}
