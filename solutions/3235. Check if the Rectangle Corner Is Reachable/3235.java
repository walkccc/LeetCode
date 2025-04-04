class UnionFind {
  public UnionFind(int n) {
    id = new int[n];
    rank = new int[n];
    for (int i = 0; i < n; ++i)
      id[i] = i;
  }

  public void unionByRank(int u, int v) {
    final int i = find(u);
    final int j = find(v);
    if (i == j)
      return;
    if (rank[i] < rank[j]) {
      id[i] = j;
    } else if (rank[i] > rank[j]) {
      id[j] = i;
    } else {
      id[i] = j;
      ++rank[j];
    }
  }

  public int find(int u) {
    return id[u] == u ? u : (id[u] = find(id[u]));
  }

  private int[] id;
  private int[] rank;
}

class Solution {
  public boolean canReachCorner(int X, int Y, int[][] circles) {
    final int n = circles.length;
    // Add two virtual nodes, where node n represents (0, 0) and node n + 1
    // represents (X, Y).
    UnionFind uf = new UnionFind(n + 2);

    // Iterate through each circle.
    for (int i = 0; i < n; ++i) {
      final int x = circles[i][0];
      final int y = circles[i][1];
      final int r = circles[i][2];
      // Union the current circle with the node (0, 0) if the circle overlaps
      // with the left or top edges.
      if (x - r <= 0 || y + r >= Y)
        uf.unionByRank(i, n);
      // Union the current circle with the node (X, Y) if the circle overlaps
      // with the right or bottom edges.
      if (x + r >= X || y - r <= 0)
        uf.unionByRank(i, n + 1);
      // Union the current circle with previous circles if they overlap.
      for (int j = 0; j < i; j++) {
        final int x2 = circles[j][0];
        final int y2 = circles[j][1];
        final int r2 = circles[j][2];
        if ((long) (x - x2) * (x - x2) + (long) (y - y2) * (y - y2) <= (long) (r + r2) * (r + r2))
          uf.unionByRank(i, j);
      }
    }

    // If nodes (0, 0) and (X, Y) are in the same union set, that means there's
    // a path of overlapping circles that connects the left or top edges to the
    // right or bottom edges, implying that (0, 0) cannot reach (X, Y).
    return uf.find(n) != uf.find(n + 1);
  }
}
