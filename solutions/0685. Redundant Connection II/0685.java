class Solution {
  public int[] findRedundantDirectedConnection(int[][] edges) {
    int[] parents = new int[edges.length + 1];
    int nodeWithTwoParents = 0;

    for (int[] edge : edges) {
      int u = edge[0];
      int v = edge[1];
      if (++parents[v] == 2)
        nodeWithTwoParents = v;
    }

    if (nodeWithTwoParents == 0)
      return findRedundantDirectedConnection(edges, -1);

    for (int i = edges.length - 1; i >= 0; --i) {
      int u = edges[i][0];
      int v = edges[i][1];
      if (v == nodeWithTwoParents)
        if (findRedundantDirectedConnection(edges, i).length == 0)
          return edges[i];
    }

    throw new IllegalArgumentException();
  }

  private int[] findRedundantDirectedConnection(int[][] edges, int skippedEdgeIndex) {
    UF uf = new UF(edges.length);

    for (int i = 0; i < edges.length; ++i) {
      if (i == skippedEdgeIndex)
        continue;
      if (!uf.union(edges[i][0], edges[i][1]))
        return edges[i];
    }

    return new int[] {};
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