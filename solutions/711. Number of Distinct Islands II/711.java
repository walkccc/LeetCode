class Solution {
  public int numDistinctIslands2(int[][] grid) {
    final int m = grid.length;
    final int n = grid[0].length;
    // all the islands with different shapes
    Set<List<Pair<Integer, Integer>>> islands = new HashSet<>();
    boolean[][] seen = new boolean[m][n];

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        List<Pair<Integer, Integer>> island = new ArrayList<>();
        dfs(grid, i, j, seen, island);
        if (!island.isEmpty())
          islands.add(normalize(island));
      }

    return islands.size();
  }

  private void dfs(int[][] grid, int i, int j, boolean[][] seen,
                   List<Pair<Integer, Integer>> island) {
    if (i < 0 || i == grid.length || j < 0 || j == grid[0].length)
      return;
    if (grid[i][j] == 0 || seen[i][j])
      return;

    seen[i][j] = true;
    island.add(new Pair<>(i, j));

    dfs(grid, i + 1, j, seen, island);
    dfs(grid, i - 1, j, seen, island);
    dfs(grid, i, j + 1, seen, island);
    dfs(grid, i, j - 1, seen, island);
  }

  private List<Pair<Integer, Integer>> normalize(List<Pair<Integer, Integer>> island) {
    // points[i] := 8 different rotations/reflections of an island
    Pair<Integer, Integer>[][] points = new Pair[8][island.size()];

    for (int k = 0; k < island.size(); ++k) {
      final int i = island.get(k).getKey();
      final int j = island.get(k).getValue();
      points[0][k] = new Pair<>(i, j);
      points[1][k] = new Pair<>(i, -j);
      points[2][k] = new Pair<>(-i, j);
      points[3][k] = new Pair<>(-i, -j);
      points[4][k] = new Pair<>(j, i);
      points[5][k] = new Pair<>(j, -i);
      points[6][k] = new Pair<>(-j, i);
      points[7][k] = new Pair<>(-j, -i);
    }

    for (Pair<Integer, Integer>[] point : points)
      Arrays.sort(point,
                  (a, b)
                      -> a.getKey().equals(b.getKey()) ? a.getValue().compareTo(b.getValue())
                                                       : a.getKey().compareTo(b.getKey()));

    // Normalize each p by substracting p[1..7] with p[0].
    for (Pair<Integer, Integer>[] p : points) {
      for (int i = 1; i < island.size(); ++i)
        p[i] = new Pair<>(p[i].getKey() - p[0].getKey(), p[i].getValue() - p[0].getValue());
      p[0] = new Pair<>(0, 0);
    }

    Arrays.sort(points, new Comparator<Pair<Integer, Integer>[]>() {
      @Override
      public int compare(Pair<Integer, Integer>[] a, Pair<Integer, Integer>[] b) {
        for (int i = 0; i < a.length; ++i) {
          if (a[i].getKey() != b[i].getKey())
            return a[i].getKey() - b[i].getKey();
          if (a[i].getValue() != b[i].getValue())
            return a[i].getValue() - b[i].getValue();
        }
        return 0;
      }
    });

    return Arrays.asList(points[0]);
  }
}
