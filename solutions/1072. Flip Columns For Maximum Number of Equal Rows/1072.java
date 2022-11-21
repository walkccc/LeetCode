class Solution {
  public int maxEqualRowsAfterFlips(int[][] matrix) {
    final int m = matrix.length;
    final int n = matrix[0].length;
    int ans = 0;
    int[] flip = new int[n];
    Set<Integer> seen = new HashSet<>();

    for (int i = 0; i < m; ++i) {
      if (seen.contains(i))
        continue;
      int count = 0;
      for (int j = 0; j < n; ++j)
        flip[j] = 1 ^ matrix[i][j];
      for (int k = 0; k < m; ++k)
        if (Arrays.equals(matrix[k], matrix[i]) || Arrays.equals(matrix[k], flip)) {
          seen.add(k);
          ++count;
        }
      ans = Math.max(ans, count);
    }

    return ans;
  }
}
