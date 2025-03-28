class Solution {
  public int minMoves(int[][] rooks) {
    final int n = rooks.length;
    int ans = 0;
    int[][] sortedByRow = rooks.clone();
    int[][] sortedByCol = rooks.clone();

    Arrays.sort(sortedByRow, Comparator.comparingInt(a -> a[0]));
    Arrays.sort(sortedByCol, Comparator.comparingInt(a -> a[1]));

    for (int i = 0; i < n; ++i) {
      ans += Math.abs(sortedByRow[i][0] - /*targetRow=*/i);
      ans += Math.abs(sortedByCol[i][1] - /*targetCol=*/i);
    }

    return ans;
  }
}
