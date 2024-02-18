class Solution {
  public double largestTriangleArea(int[][] points) {
    double ans = 0;

    for (int[] A : points)
      for (int[] B : points)
        for (int[] C : points)
          ans = Math.max(ans, 0.5 * Math.abs((B[0] - A[0]) * (C[1] - A[1]) - //
                                             (C[0] - A[0]) * (B[1] - A[1])));

    return ans;
  }
}
