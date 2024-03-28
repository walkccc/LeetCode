class Solution {
  public double getMinDistSum(int[][] positions) {
    final double kErr = 1e-6;
    double currX = 50;
    double currY = 50;
    double ans = distSum(positions, currX, currY);
    double step = 1;

    while (step > kErr) {
      boolean shouldDecreaseStep = true;
      for (double[] dirs : new double[][] {{0, step}, {0, -step}, {step, 0}, {-step, 0}}) {
        final double x = currX + dirs[0];
        final double y = currY + dirs[1];
        final double newDistSum = distSum(positions, x, y);
        if (newDistSum < ans) {
          ans = newDistSum;
          currX = x;
          currY = y;
          shouldDecreaseStep = false;
        }
      }
      if (shouldDecreaseStep)
        step /= 10;
    }

    return ans;
  }

  private double distSum(int[][] positions, double a, double b) {
    double sum = 0;
    for (int[] p : positions)
      sum += Math.sqrt(Math.pow(a - p[0], 2) + Math.pow(b - p[1], 2));
    return sum;
  }
}
