class Solution {
  public int minDistance(int height, int width, int[] tree, int[] squirrel, int[][] nuts) {
    int totDist = 0;
    int maxSave = Integer.MIN_VALUE;

    for (int[] nut : nuts) {
      totDist += dist(nut, tree) * 2;
      maxSave = Math.max(maxSave, dist(nut, tree) - dist(nut, squirrel));
    }

    return totDist - maxSave;
  }

  private int dist(int[] a, int[] b) {
    return Math.abs(a[0] - b[0]) + Math.abs(a[1] - b[1]);
  }
}
