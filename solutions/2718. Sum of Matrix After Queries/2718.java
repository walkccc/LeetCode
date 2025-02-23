class Solution {
  public long matrixSumQueries(int n, int[][] queries) {
    long ans = 0;
    // seen[0] := row, seen[1] := col
    boolean[][] seen = new boolean[2][n];
    // notSet[0] = row, notSet[1] := col
    int[] notSet = new int[2];
    Arrays.fill(notSet, n);

    // Late queries dominate.
    for (int i = queries.length - 1; i >= 0; --i) {
      final int type = queries[i][0];
      final int index = queries[i][1];
      final int val = queries[i][2];
      if (!seen[type][index]) {
        ans += val * notSet[type ^ 1];
        seen[type][index] = true;
        --notSet[type];
      }
    }

    return ans;
  }
}
