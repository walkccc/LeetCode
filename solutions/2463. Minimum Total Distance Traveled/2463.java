class Solution {
  public long minimumTotalDistance(List<Integer> robot, int[][] factory) {
    Collections.sort(robot);
    Arrays.sort(factory, (a, b) -> Integer.compare(a[0], b[0]));
    long[][][] mem = new long[robot.size()][factory.length][robot.size()];
    return minimumTotalDistance(robot, factory, 0, 0, 0, mem);
  }

  private long minimumTotalDistance(List<Integer> robot, int[][] factory, int i, int j, int k,
                                    long[][][] mem) {
    if (i == robot.size())
      return 0;
    if (j == factory.length)
      return Long.MAX_VALUE;
    if (mem[i][j][k] > 0)
      return mem[i][j][k];
    final long skipFactory = minimumTotalDistance(robot, factory, i, j + 1, 0, mem);
    final int position = factory[j][0];
    final int limit = factory[j][1];
    final long useFactory = limit > k ? minimumTotalDistance(robot, factory, i + 1, j, k + 1, mem) +
                                            Math.abs(robot.get(i) - position)
                                      : Long.MAX_VALUE / 2;
    return mem[i][j][k] = Math.min(skipFactory, useFactory);
  }
}
