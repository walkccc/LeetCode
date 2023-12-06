class Solution {
  public int removeBoxes(int[] boxes) {
    final int n = boxes.length;
    // dp[i][j][k] := the maximum score of boxes[i..j] if k boxes eqaul to boxes[j]
    dp = new int[n][n][n];
    return removeBoxes(boxes, 0, n - 1, 0);
  }

  private int[][][] dp;

  private int removeBoxes(int[] boxes, int i, int j, int k) {
    if (i > j)
      return 0;
    if (dp[i][j][k] > 0)
      return dp[i][j][k];

    int r = j;
    int sameBoxes = k + 1;
    while (r > 0 && boxes[r - 1] == boxes[r]) {
      --r;
      ++sameBoxes;
    }
    dp[i][j][k] = removeBoxes(boxes, i, r - 1, 0) + sameBoxes * sameBoxes;

    for (int p = i; p < r; ++p)
      if (boxes[p] == boxes[r])
        dp[i][j][k] = Math.max(dp[i][j][k], removeBoxes(boxes, i, p, sameBoxes) +
                                                removeBoxes(boxes, p + 1, r - 1, 0));

    return dp[i][j][k];
  }
}
