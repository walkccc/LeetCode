class Solution {
  public int maxCount(int m, int n, int[][] ops) {
    int minY = m;
    int minX = n;

    for (int[] op : ops) {
      minY = Math.min(minY, op[0]);
      minX = Math.min(minX, op[1]);
    }

    return minX * minY;
  }
}
