class Solution {
  public int[] countPoints(int[][] points, int[][] queries) {
    int[] ans = new int[queries.length];

    for (int i = 0; i < queries.length; ++i) {
      final int xj = queries[i][0];
      final int yj = queries[i][1];
      final int rj = queries[i][2];
      int count = 0;
      for (int[] point : points) {
        final int xi = point[0];
        final int yi = point[1];
        if (squared(xi - xj) + squared(yi - yj) <= squared(rj))
          ++count;
      }
      ans[i] = count;
    }

    return ans;
  }

  private int squared(int x) {
    return x * x;
  }
}
