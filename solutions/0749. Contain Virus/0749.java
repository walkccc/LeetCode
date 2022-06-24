class Region {
  // given m = # of rows and n = # of cols, (x, y) will be hashed as x * n + y
  public Set<Integer> infected = new HashSet<>();
  public Set<Integer> noninfected = new HashSet<>(); // noninfected neighbors
  public int wallsRequired = 0;
};

class Solution {
  public int containVirus(int[][] grid) {
    final int m = grid.length;
    final int n = grid[0].length;
    int ans = 0;

    while (true) {
      List<Region> regions = new ArrayList<>();
      boolean[][] seen = new boolean[m][n];

      for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
          if (grid[i][j] == 1 && !seen[i][j]) {
            Region region = new Region();
            dfs(grid, i, j, region, seen); // use DFS to find all regions (1s)
            if (!region.noninfected.isEmpty())
              regions.add(region);
          }

      if (regions.isEmpty())
        break; // no region causes further infection

      // region which infects most neighbors is in the back
      Collections.sort(regions, (a, b) -> a.noninfected.size() - b.noninfected.size());

      // build walls around the region which infects most neighbors
      Region mostInfectedRegion = regions.get(regions.size() - 1);
      regions.remove(regions.size() - 1);
      ans += mostInfectedRegion.wallsRequired;

      for (final int neighbor : mostInfectedRegion.infected) {
        final int i = neighbor / n;
        final int j = neighbor % n;
        // the grid is now contained and won't be infected anymore
        grid[i][j] = 2;
      }

      // for remaining regions, expand (infect their neighbors)
      for (final Region region : regions)
        for (final int neighbor : region.noninfected) {
          final int i = neighbor / n;
          final int j = neighbor % n;
          grid[i][j] = 1;
        }
    }

    return ans;
  }

  private void dfs(int[][] grid, int i, int j, Region region, boolean[][] seen) {
    if (i < 0 || i == grid.length || j < 0 || j == grid[0].length)
      return;
    if (seen[i][j] || grid[i][j] == 2)
      return;
    if (grid[i][j] == 0) {
      region.noninfected.add(i * grid[0].length + j);
      ++region.wallsRequired;
      return;
    }

    // grid[i][j] == 1
    seen[i][j] = true;
    region.infected.add(i * grid[0].length + j);

    dfs(grid, i + 1, j, region, seen);
    dfs(grid, i - 1, j, region, seen);
    dfs(grid, i, j + 1, region, seen);
    dfs(grid, i, j - 1, region, seen);
  }
}
