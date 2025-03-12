class Solution {
  public int numDistinctIslands(int[][] grid) {
    final int m = grid.length;
    final int n = grid[0].length;
    Set<List<Pair<Integer, Integer>>> islands = new HashSet<>(); // all the different islands
    boolean[][] seen = new boolean[m][n];

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        List<Pair<Integer, Integer>> island = new ArrayList<>();
        dfs(grid, i, j, i, j, seen, island);
        if (!island.isEmpty())
          islands.add(island);
      }

    return islands.size();
  }

  private void dfs(int[][] grid, int i, int j, int i0, int j0, boolean[][] seen,
                   List<Pair<Integer, Integer>> island) {
    if (i < 0 || i == grid.length || j < 0 || j == grid[0].length)
      return;
    if (grid[i][j] == 0 || seen[i][j])
      return;

    seen[i][j] = true;
    island.add(new Pair<>(i - i0, j - j0));

    dfs(grid, i + 1, j, i0, j0, seen, island);
    dfs(grid, i - 1, j, i0, j0, seen, island);
    dfs(grid, i, j + 1, i0, j0, seen, island);
    dfs(grid, i, j - 1, i0, j0, seen, island);
  }
}
