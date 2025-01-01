class UnionFind {
  public void union(int u, int v) {
    id.putIfAbsent(u, u);
    id.putIfAbsent(v, v);
    final int i = find(u);
    final int j = find(v);
    if (i != j)
      id.put(i, j);
  }

  public Map<Integer, List<Integer>> getGroupIdToValues() {
    Map<Integer, List<Integer>> groupIdToValues = new HashMap<>();
    for (Map.Entry<Integer, Integer> entry : id.entrySet()) {
      final int u = entry.getKey();
      final int i = find(u);
      groupIdToValues.putIfAbsent(i, new ArrayList<>());
      groupIdToValues.get(i).add(u);
    }
    return groupIdToValues;
  }

  private Map<Integer, Integer> id = new HashMap<>();

  private int find(int u) {
    return id.getOrDefault(u, u) == u ? u : find(id.get(u));
  }
}

class Solution {
  public int[][] matrixRankTransform(int[][] matrix) {
    final int m = matrix.length;
    final int n = matrix[0].length;
    int[][] ans = new int[m][n];
    // {val: [(i, j)]}
    TreeMap<Integer, List<Pair<Integer, Integer>>> valToGrids = new TreeMap<>();
    // rank[i] := the maximum rank of the row or column so far
    int[] maxRankSoFar = new int[m + n];

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        final int val = matrix[i][j];
        valToGrids.putIfAbsent(val, new ArrayList<>());
        valToGrids.get(val).add(new Pair<>(i, j));
      }

    for (Map.Entry<Integer, List<Pair<Integer, Integer>>> entry : valToGrids.entrySet()) {
      final int val = entry.getKey();
      List<Pair<Integer, Integer>> grids = entry.getValue();
      UnionFind uf = new UnionFind();
      for (Pair<Integer, Integer> grid : grids) {
        final int i = grid.getKey();
        final int j = grid.getValue();
        // Union i-th row with j-th col.
        uf.union(i, j + m);
      }
      for (List<Integer> values : uf.getGroupIdToValues().values()) {
        // Get the maximum rank of all the included rows and columns.
        int maxRank = 0;
        for (final int i : values)
          maxRank = Math.max(maxRank, maxRankSoFar[i]);
        // Update all the rows and columns to maxRank + 1.
        for (final int i : values)
          maxRankSoFar[i] = maxRank + 1;
      }
      for (Pair<Integer, Integer> grid : grids) {
        final int i = grid.getKey();
        final int j = grid.getValue();
        ans[i][j] = maxRankSoFar[i];
      }
    }

    return ans;
  }
}
