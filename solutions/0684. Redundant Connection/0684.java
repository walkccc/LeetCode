class UF {
  public UF(int n) {
    parent = new int[n];

    for (int i = 0; i < n; ++i)
      parent[i] = i;
  }

  public boolean union(int u, int v) {
    final int pu = find(u);
    final int pv = find(v);
    if (pu == pv)
      return false;

    parent[pu] = pv;
    return true;
  }

  private int[] parent;

  private int find(int u) {
    if (u != parent[u])
      parent[u] = find(parent[u]);
    return parent[u];
  }
}

class Solution {
  public int[] findRedundantConnection(int[][] edges) {
    UF uf = new UF(edges.length + 1);

    for (int[] edge : edges)
      if (!uf.union(edge[0], edge[1]))
        return edge;

    throw new IllegalArgumentException();
  }
}
