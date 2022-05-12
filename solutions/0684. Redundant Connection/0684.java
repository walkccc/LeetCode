class UF {
  public UF(int n) {
    id = new int[n];
    for (int i = 0; i < n; ++i)
      id[i] = i;
  }

  public boolean union(int u, int v) {
    final int i = find(u);
    final int j = find(v);
    if (i == j)
      return false;
    id[i] = j;
    return true;
  }

  private int[] id;

  private int find(int u) {
    return id[u] == u ? u : (id[u] = find(id[u]));
  }
}

class Solution {
  public int[] findRedundantConnection(int[][] edges) {
    UF uf = new UF(edges.length + 1);

    for (int[] e : edges)
      if (!uf.union(e[0], e[1]))
        return edge;

    throw new IllegalArgumentException();
  }
}
