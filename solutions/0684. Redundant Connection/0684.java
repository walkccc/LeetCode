class Solution {
  public int[] findRedundantConnection(int[][] edges) {
    UF uf = new UF(edges.length);

    for (int[] edge : edges)
      if (!uf.union(edge[0], edge[1]))
        return edge;

    throw new IllegalArgumentException();
  }
}

class UF {
  public UF(int n) {
    rank = new int[n + 1];
    parent = new int[n + 1];

    for (int i = 0; i < parent.length; ++i)
      parent[i] = i;
  }

  public boolean union(int u, int v) {
    int pu = find(u);
    int pv = find(v);
    if (pu == pv)
      return false;

    if (rank[pu] < rank[pv])
      parent[pu] = pv;
    else if (rank[pv] < rank[pu])
      parent[pv] = pu;
    else {
      parent[pu] = pv;
      ++rank[pv];
    }

    return true;
  }

  public int find(int u) {
    while (u != parent[u]) {
      parent[u] = parent[parent[u]];
      u = parent[u];
    }

    return u;
  }

  private int[] rank;
  private int[] parent;
}