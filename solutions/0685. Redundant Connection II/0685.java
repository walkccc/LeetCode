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
  public int[] findRedundantDirectedConnection(int[][] edges) {
    int[] ids = new int[edges.length + 1];
    int nodeWithTwoParents = 0;

    for (int[] e : edges) {
      final int v = e[1];
      if (++ids[v] == 2) {
        nodeWithTwoParents = v;
        break;
      }
    }

    // if there is no edge with two ids
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
