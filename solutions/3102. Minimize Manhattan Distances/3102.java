class Solution {
  public int minimumDistance(int[][] points) {
    final int[] maxIndices = maxManhattanDistance(points, -1);
    final int[] xiyi = maxManhattanDistance(points, maxIndices[0]);
    final int[] xjyj = maxManhattanDistance(points, maxIndices[1]);
    return Math.min(manhattan(points, xiyi[0], xiyi[1]), //
                    manhattan(points, xjyj[0], xjyj[1]));
  }

  // Returns the pair of indices a and b where points[a] and points[b] have the
  // maximum Manhattan distance and a != excludedIndex and b != excludedIndex.
  private int[] maxManhattanDistance(int[][] points, int excludedIndex) {
    int minSum = Integer.MAX_VALUE;
    int maxSum = Integer.MIN_VALUE;
    int minDiff = Integer.MAX_VALUE;
    int maxDiff = Integer.MIN_VALUE;
    int minSumIndex = -1;
    int maxSumIndex = -1;
    int minDiffIndex = -1;
    int maxDiffIndex = -1;

    for (int i = 0; i < points.length; ++i) {
      if (i == excludedIndex)
        continue;
      final int x = points[i][0];
      final int y = points[i][1];
      final int sum = x + y;
      final int diff = x - y;
      if (sum < minSum) {
        minSum = sum;
        minSumIndex = i;
      }
      if (sum > maxSum) {
        maxSum = sum;
        maxSumIndex = i;
      }
      if (diff < minDiff) {
        minDiff = diff;
        minDiffIndex = i;
      }
      if (diff > maxDiff) {
        maxDiff = diff;
        maxDiffIndex = i;
      }
    }

    return maxSum - minSum >= maxDiff - minDiff ? new int[] {minSumIndex, maxSumIndex}
                                                : new int[] {minDiffIndex, maxDiffIndex};
  }

  private int manhattan(int[][] points, int i, int j) {
    return Math.abs(points[i][0] - points[j][0]) + Math.abs(points[i][1] - points[j][1]);
  }
}
