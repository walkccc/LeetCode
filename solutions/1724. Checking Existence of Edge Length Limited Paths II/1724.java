class UnionFind {
  public UnionFind(int n) {
    id = new TreeMap[n];
    for (int i = 0; i < n; ++i) {
      id[i] = new TreeMap<>();
      id[i].put(0, i);
    }
  }

  public void union(int u, int v, int limit) {
    final int i = find(u, limit);
    final int j = find(v, limit);
    if (i == j)
      return;
    id[i].put(limit, j);
  }

  public int find(int u, int limit) {
    // the maximum key of id[u] <= limit
    final int floorKey = id[u].floorKey(limit);
    final int i = id[u].get(floorKey);
    if (i == u)
      return u;
    // Recursively find i's id.
    final int j = find(i, limit);
    id[u].put(limit, j);
    return j;
  }

  // id[i]'s (key, value) := (limit, id of node i <= limit)
  private TreeMap<Integer, Integer>[] id;
}

class DistanceLimitedPathsExist {
  public DistanceLimitedPathsExist(int n, int[][] edgeList) {
    uf = new UnionFind(n);

    Arrays.sort(edgeList, (a, b) -> Integer.compare(a[2], b[2]));

    for (int[] edge : edgeList) {
      final int u = edge[0];
      final int v = edge[1];
      final int d = edge[2];
      uf.union(u, v, d);
    }
  }

  public boolean query(int p, int q, int limit) {
    return uf.find(p, limit - 1) == uf.find(q, limit - 1);
  }

  private UnionFind uf;
}
