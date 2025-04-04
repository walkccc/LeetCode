class UnionFind {
  public UnionFind(int n) {
    id = new int[n];
    rank = new int[n];
    for (int i = 0; i < n; ++i)
      id[i] = i;
  }

  public boolean unionByRank(int u, int v) {
    final int i = find(u);
    final int j = find(v);
    if (i == j)
      return false;
    if (rank[i] < rank[j]) {
      id[i] = j;
    } else if (rank[i] > rank[j]) {
      id[j] = i;
    } else {
      id[i] = j;
      ++rank[j];
    }
    return true;
  }

  private int[] id;
  private int[] rank;

  private int find(int u) {
    return id[u] == u ? u : (id[u] = find(id[u]));
  }
}

class Solution {
  public int[] findRedundantDirectedConnection(int[][] edges) {
    int[] ids = new int[edges.length + 1];
    int nodeWithTwoParents = 0;

    for (int[] edge : edges) {
      final int v = edge[1];
      if (++ids[v] == 2) {
        nodeWithTwoParents = v;
        break;
      }
    }

    // If there is no edge with two ids, don't skip any edge.
    if (nodeWithTwoParents == 0)
      return findRedundantDirectedConnection(edges, -1);

    for (int i = edges.length - 1; i >= 0; --i)
      if (edges[i][1] == nodeWithTwoParents)
        // Try to delete the edges[i].
        if (findRedundantDirectedConnection(edges, i).length == 0)
          return edges[i];

    throw new IllegalArgumentException();
  }

  private int[] findRedundantDirectedConnection(int[][] edges, int skippedEdgeIndex) {
    UnionFind uf = new UnionFind(edges.length + 1);

    for (int i = 0; i < edges.length; ++i) {
      if (i == skippedEdgeIndex)
        continue;
      if (!uf.unionByRank(edges[i][0], edges[i][1]))
        return edges[i];
    }

    return new int[] {};
  }
}
