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
  public int[] findRedundantDirectedConnection(int[][] edges) {
    int[] parents = new int[edges.length + 1];
    int nodeWithTwoParents = 0;

    for (int[] edge : edges) {
      final int v = edge[1];
      if (++parents[v] == 2) {
        nodeWithTwoParents = v;
        break;
      }
    }

    // if there is no edge with two parents
    // we don't have to skip any edge
    if (nodeWithTwoParents == 0)
      return findRedundantDirectedConnection(edges, -1);

    for (int i = edges.length - 1; i >= 0; --i)
      if (edges[i][1] == nodeWithTwoParents)
        // try to delete edges[i]
        if (findRedundantDirectedConnection(edges, i).length == 0)
          return edges[i];

    throw new IllegalArgumentException();
  }

  private int[] findRedundantDirectedConnection(int[][] edges, int skippedEdgeIndex) {
    UF uf = new UF(edges.length + 1);

    for (int i = 0; i < edges.length; ++i) {
      if (i == skippedEdgeIndex)
        continue;
      if (!uf.union(edges[i][0], edges[i][1]))
        return edges[i];
    }

    return new int[] {};
  }
}
