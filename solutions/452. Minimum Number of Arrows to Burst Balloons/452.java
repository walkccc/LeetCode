class Solution {
  public int findMinArrowShots(int[][] points) {
    Arrays.sort(points, (a, b) -> Integer.compare(a[1], b[1]));

    int ans = 1;
    int arrowX = points[0][1];

    for (int i = 1; i < points.length; ++i)
      if (points[i][0] > arrowX) {
        arrowX = points[i][1];
        ++ans;
      }

    return ans;
  }
}
