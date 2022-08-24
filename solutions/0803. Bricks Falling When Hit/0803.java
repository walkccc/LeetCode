class UF {
  public UF(int n) {
    id = new int[n];
    size = new int[n];
    for (int i = 0; i < n; ++i)
      id[i] = i;
    Arrays.fill(size, 1);
  }

  public void union(int u, int v) {
    final int i = find(u);
    final int j = find(v);
    if (i == j)
      return;
    id[i] = j;
    size[j] += size[i];
  }

  public int getStableSize() {
    // bricks connected with 0 (top) are stable
    return size[find(0)];
  }

  private int[] id;
  private int[] size;

  private int find(int u) {
    return id[u] == u ? u : (id[u] = find(id[u]));
  }
}
class Solution {
  public int[] hitBricks(int[][] grid, int[][] hits) {
    this.m = grid.length;
    this.n = grid[0].length;

    UF uf = new UF(m * n + 1); // 0 := top (stable)

    // mark cells to hit as 2
    for (int[] hit : hits) {
      final int i = hit[0];
      final int j = hit[1];
      if (grid[i][j] == 1)
        grid[i][j] = 2;
    }

    // union all 1s
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (grid[i][j] == 1)
          unionNeighbors(grid, uf, i, j);

    int[] ans = new int[hits.length];
    int stableSize = uf.getStableSize();

    for (int i = hits.length - 1; i >= 0; --i) {
      final int x = hits[i][0];
      final int y = hits[i][1];
      if (grid[x][y] == 2) { // cells marked from 1 to 2
        grid[x][y] = 1;      // unhit, restore back to 1
        unionNeighbors(grid, uf, x, y);
        final int newStableSize = uf.getStableSize();
        if (newStableSize > stableSize)
          ans[i] = newStableSize - stableSize - 1; // 1 := the hit cell
        stableSize = newStableSize;
      }
    }

    return ans;
  }

  private int m;
  private int n;
  private static final int[] dirs = {0, 1, 0, -1, 0};

  private void unionNeighbors(int[][] grid, UF uf, int i, int j) {
    final int hashed = hash(i, j);

    for (int k = 0; k < 4; ++k) {
      final int x = i + dirs[k];
      final int y = j + dirs[k + 1];
      if (x < 0 || x == m || y < 0 || y == n)
        continue;
      if (grid[x][y] != 1)
        continue;
      uf.union(hashed, hash(x, y));
    }

    if (i == 0)
      uf.union(hashed, 0);
  }

  private int hash(int i, int j) {
    return i * n + j + 1;
  }
}
