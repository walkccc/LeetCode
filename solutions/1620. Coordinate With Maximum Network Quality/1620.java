class Solution {
  public int[] bestCoordinate(int[][] towers, int radius) {
    final int kMax = 50;
    final int n = towers.length;
    int[] ans = new int[2];
    int maxQuality = 0;

    for (int i = 0; i <= kMax; ++i) {
      for (int j = 0; j <= kMax; ++j) {
        int qualitySum = 0;
        for (int[] tower : towers) {
          double d = dist(tower, i, j);
          if (d <= radius) {
            final int q = tower[2];
            qualitySum += (int) (q / (1 + d));
          }
        }
        if (qualitySum > maxQuality) {
          maxQuality = qualitySum;
          ans[0] = i;
          ans[1] = j;
        }
      }
    }

    return ans;
  }

  // Returns the distance between the tower and the coordinate.
  private double dist(int[] tower, int i, int j) {
    return Math.sqrt(Math.pow(tower[0] - i, 2) + Math.pow(tower[1] - j, 2));
  }
}
