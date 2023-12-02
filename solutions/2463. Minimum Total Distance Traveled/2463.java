public class Solution {
  public long minimumTotalDistance(List<Integer> robot, int[][] factory) {
    Collections.sort(robot);
    Arrays.sort(factory, (a, b) -> (a[0] - b[0]));

    // dp[i][j][k] := the minimum distance to fix robot[i..n) with factory[j..n), where
    // factory[j] already fixed k robots
    dp = new long[robot.size()][factory.length][robot.size()];
    return minimumTotalDistance(robot, factory, 0, 0, 0);
  }

  private long[][][] dp;

  private long minimumTotalDistance(List<Integer> robot, int[][] factory, int i, int j, int k) {
    if (i == robot.size())
      return 0;
    if (j == factory.length)
      return Long.MAX_VALUE;
    if (dp[i][j][k] > 0)
      return dp[i][j][k];
    final long skipFactory = minimumTotalDistance(robot, factory, i, j + 1, 0);
    final int position = factory[j][0];
    final int limit = factory[j][1];
    final long useFactory = limit > k ? minimumTotalDistance(robot, factory, i + 1, j, k + 1) +
                                            Math.abs(robot.get(i) - position)
                                      : Long.MAX_VALUE / 2;
    return dp[i][j][k] = Math.min(skipFactory, useFactory);
  }
}
