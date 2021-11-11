class Solution {
  public int removeBoxes(int[] boxes) {
    final int n = boxes.length;

    // dp[i][j][k] := max score of boxes[i..j] if k boxes eqaul to boxes[j]
    dp = new int[n][n][n];

    return removeBoxes(boxes, 0, n - 1, 0);
  }

  private int[][][] dp;

  private int removeBoxes(int[] boxes, int i, int j, int k) {
    if (i > j)
      return 0;
    if (dp[i][j][k] > 0)
      return dp[i][j][k];

    dp[i][j][k] = removeBoxes(boxes, i, j - 1, 0) + (k + 1) * (k + 1);

    for (int p = i; p < j; ++p)
      if (boxes[p] == boxes[j])
        dp[i][j][k] = Math.max(
            dp[i][j][k],
            removeBoxes(boxes, i, p, k + 1) +
            removeBoxes(boxes, p + 1, j - 1, 0));

    return dp[i][j][k];
  }
}
