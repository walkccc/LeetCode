class Region {
  // Given m = the number of rows and n = the number of columns, (x, y) will be
  // hashed as x * n + y.
  public Set<Integer> infected = new HashSet<>();
  public Set<Integer> noninfected = new HashSet<>();
  public int wallsRequired = 0;
}

class Solution {
  public int containVirus(int[][] isInfected) {
    final int m = isInfected.length;
    final int n = isInfected[0].length;
    int ans = 0;

    while (true) {
      List<Region> regions = new ArrayList<>();
      boolean[][] seen = new boolean[m][n];

      for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
          if (isInfected[i][j] == 1 && !seen[i][j]) {
            Region region = new Region();
            // Use DFS to find all the regions (1s).
            dfs(isInfected, i, j, region, seen);
            if (!region.noninfected.isEmpty())
              regions.add(region);
          }

      if (regions.isEmpty())
        break; // No region causes further infection.

      // Regions that infect the most neighbors will be sorted to the back of
      // the array.
      Collections.sort(regions, (a, b) -> a.noninfected.size() - b.noninfected.size());

      // Build walls around the region that infects the most neighbors.
      Region mostInfectedRegion = regions.get(regions.size() - 1);
      regions.remove(regions.size() - 1);
      ans += mostInfectedRegion.wallsRequired;

      for (final int neighbor : mostInfectedRegion.infected) {
        final int i = neighbor / n;
        final int j = neighbor % n;
        // The isInfected is now contained and won't be infected anymore.
        isInfected[i][j] = 2;
      }

      // For remaining regions, infect their neighbors.
      for (final Region region : regions)
        for (final int neighbor : region.noninfected) {
          final int i = neighbor / n;
          final int j = neighbor % n;
          isInfected[i][j] = 1;
        }
    }

    return ans;
  }

  private void dfs(int[][] isInfected, int i, int j, Region region, boolean[][] seen) {
    if (i < 0 || i == isInfected.length || j < 0 || j == isInfected[0].length)
      return;
    if (seen[i][j] || isInfected[i][j] == 2)
      return;
    if (isInfected[i][j] == 0) {
      region.noninfected.add(i * isInfected[0].length + j);
      ++region.wallsRequired;
      return;
    }

    // isInfected[i][j] == 1
    seen[i][j] = true;
    region.infected.add(i * isInfected[0].length + j);

    dfs(isInfected, i + 1, j, region, seen);
    dfs(isInfected, i - 1, j, region, seen);
    dfs(isInfected, i, j + 1, region, seen);
    dfs(isInfected, i, j - 1, region, seen);
  }
}
