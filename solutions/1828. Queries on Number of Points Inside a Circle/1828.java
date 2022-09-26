class Solution {
  public int[] countPoints(int[][] points, int[][] queries) {
    int[] ans = new int[queries.length];

    for (int i = 0; i < queries.length; ++i) {
      int[] q = queries[i];
      final int rSquared = q[2] * q[2];
      int count = 0;
      for (int[] p : points)
        if (squared(p[0] - q[0]) + squared(p[1] - q[1]) <= rSquared)
          ++count;
      ans[i] = count;
    }

    return ans;
  }

  private int squared(int x) {
    return x * x;
  }
}
