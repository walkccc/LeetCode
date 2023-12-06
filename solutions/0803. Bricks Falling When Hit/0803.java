class UnionFind {
  public UnionFind(int n) {
    id = new int[n];
    sz = new int[n];
    for (int i = 0; i < n; ++i)
      id[i] = i;
    Arrays.fill(sz, 1);
  }

  public void unionBySize(int u, int v) {
    final int i = find(u);
    final int j = find(v);
    if (i == j)
      return;
    if (sz[i] < sz[j]) {
      sz[j] += sz[i];
      id[i] = j;
    } else {
      sz[i] += sz[j];
      id[j] = i;
    }
  }

  public int getStableSize() {
    // Bricks connected with 0 (top) are stable.
    return sz[find(0)];
  }

  private int[] id;
  private int[] sz;

  private int find(int u) {
    return id[u] == u ? u : (id[u] = find(id[u]));
  }
}
class Solution {
  public int[] hitBricks(int[][] grid, int[][] hits) {
    this.m = grid.length;
    this.n = grid[0].length;

    UnionFind uf = new UnionFind(m * n + 1); // 0 := top (stable)

    // Mark cells to hit as 2.
    for (int[] hit : hits) {
      final int i = hit[0];
      final int j = hit[1];
      if (grid[i][j] == 1)
        grid[i][j] = 2;
    }

    // Union all the 1s.
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
        grid[x][y] = 1;      // Unhit and restore it back to 1.
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

  private void unionNeighbors(int[][] grid, UnionFind uf, int i, int j) {
    final int hash = getHash(i, j);

    for (int k = 0; k < 4; ++k) {
      final int x = i + dirs[k];
      final int y = j + dirs[k + 1];
      if (x < 0 || x == m || y < 0 || y == n)
        continue;
      if (grid[x][y] != 1)
        continue;
      uf.unionBySize(hash, getHash(x, y));
    }

    if (i == 0)
      uf.unionBySize(hash, 0);
  }

  private int getHash(int i, int j) {
    return i * n + j + 1;
  }
}
