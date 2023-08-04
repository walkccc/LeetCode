class Solution {
  public int maxIncreasingCells(int[][] mat) {
    final int m = mat.length;
    final int n = mat[0].length;
    int[] rows = new int[m]; // rows[i] := max path length for i-th row
    int[] cols = new int[n]; // cols[j] := max path length for j-th col
    Map<Integer, ArrayList<Pair<Integer, Integer>>> valToIndices = new HashMap<>();
    // maxPathLength[i][j] := max path length from mat[i][j]
    int[][] maxPathLength = new int[m][n];
    // all unique values in the matrix in non-increasing order
    TreeSet<Integer> decreasingSet = new TreeSet<>(Comparator.reverseOrder());

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        final int val = mat[i][j];
        valToIndices.putIfAbsent(val, new ArrayList<>());
        valToIndices.get(val).add(new Pair<>(i, j));
        decreasingSet.add(val);
      }

    for (final int val : decreasingSet) {
      for (Pair<Integer, Integer> pair : valToIndices.get(val)) {
        final int i = pair.getKey();
        final int j = pair.getValue();
        maxPathLength[i][j] = Math.max(rows[i], cols[j]) + 1;
      }
      for (Pair<Integer, Integer> pair : valToIndices.get(val)) {
        final int i = pair.getKey();
        final int j = pair.getValue();
        rows[i] = Math.max(rows[i], maxPathLength[i][j]);
        cols[j] = Math.max(cols[j], maxPathLength[i][j]);
      }
    }

    return Math.max(Arrays.stream(rows).max().getAsInt(), //
                    Arrays.stream(cols).max().getAsInt());
  }
}
