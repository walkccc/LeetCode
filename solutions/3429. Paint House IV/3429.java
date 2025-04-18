class Solution {
  public long minCost(int n, int[][] costs) {
    final int INVALID_COLOR = 3;
    Long[][][] mem = new Long[n / 2][4][4];
    return minCost(costs, 0, INVALID_COLOR, INVALID_COLOR, mem);
  }

  private long minCost(int[][] costs, int i, int prevLeftColor, int prevRightColor,
                       Long[][][] mem) {
    if (i == costs.length / 2)
      return 0;
    if (mem[i][prevLeftColor][prevRightColor] != null)
      return mem[i][prevLeftColor][prevRightColor];

    long res = Long.MAX_VALUE;

    for (final int leftColor : getValidColors(prevLeftColor))
      for (final int rightColor : getValidColors(prevRightColor)) {
        if (leftColor == rightColor)
          continue;
        final long leftCost = costs[i][leftColor];
        final long rightCost = costs[costs.length - 1 - i][rightColor];
        res =
            Math.min(res, leftCost + rightCost + minCost(costs, i + 1, leftColor, rightColor, mem));
      }

    return mem[i][prevLeftColor][prevRightColor] = res;
  }

  private List<Integer> getValidColors(int prevColor) {
    List<Integer> validColors = new ArrayList<>();
    for (int color = 0; color < 3; ++color)
      if (color != prevColor)
        validColors.add(color);
    return validColors;
  }
}
