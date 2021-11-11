class UF {
  public UF(int n) {
    parent = new TreeMap[n];

    for (int i = 0; i < n; ++i) {
      parent[i] = new TreeMap<>();
      parent[i].put(0, i);
    }
  }

  public void union(int u, int v, int limit) {
    final int pu = find(u, limit);
    final int pv = find(v, limit);
    if (pu == pv)
      return;
    parent[pu].put(limit, pv);
  }

  public int find(int u, int limit) {
    // max key of parent[u] <= limit
    final int floorKey = parent[u].floorKey(limit);
    final int pu = parent[u].get(floorKey);
    if (pu == u)
      return u;
    // recursively find pu's parent
    final int ppu = find(pu, limit);
    parent[u].put(limit, ppu);
    return ppu;
  }

  // parent[i]'s (key, value) := (limit, parent of node i <= limit)
  private TreeMap<Integer, Integer>[] parent;
}

class DistanceLimitedPathsExist {
  public DistanceLimitedPathsExist(int n, int[][] edgeList) {
    uf = new UF(n);

    Arrays.sort(edgeList, (a, b) -> a[2] - b[2]);

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

  private UF uf;
}
