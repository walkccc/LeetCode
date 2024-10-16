class Solution {
  public int[][] minScore(int[][] grid) {
    final int m = grid.length;
    final int n = grid[0].length;
    int[][] ans = new int[m][n];
    List<int[]> valAndIndices = new ArrayList<>();
    int[] rows = new int[m]; // rows[i] := the maximum used number so far
    int[] cols = new int[n]; // cols[j] := the maximum used number so far

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        valAndIndices.add(new int[] {grid[i][j], i, j});

    Collections.sort(valAndIndices, new Comparator<int[]>() {
      @Override
      public int compare(int[] a, int[] b) {
        return Integer.compare(a[0], b[0]);
      }
    });

    for (int[] valAndIndex : valAndIndices) {
      final int i = valAndIndex[1];
      final int j = valAndIndex[2];
      final int nextAvailable = Math.max(rows[i], cols[j]) + 1;
      ans[i][j] = nextAvailable;
      rows[i] = nextAvailable;
      cols[j] = nextAvailable;
    }

    return ans;
  }
}
