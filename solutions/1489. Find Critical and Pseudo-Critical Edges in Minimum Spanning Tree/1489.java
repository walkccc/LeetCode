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
  public List<List<Integer>> findCriticalAndPseudoCriticalEdges(int n, int[][] edges) {
    List<Integer> criticalEdges = new ArrayList<>();
    List<Integer> pseudoCriticalEdges = new ArrayList<>();

    // Record the index information, so edges[i] := (u, v, weight, index).
    for (int i = 0; i < edges.length; ++i)
      edges[i] = new int[] {edges[i][0], edges[i][1], edges[i][2], i};

    // Sort by the weight.
    Arrays.sort(edges, (a, b) -> Integer.compare(a[2], b[2]));

    final int mstWeight = getMSTWeight(n, edges, new int[] {}, -1);

    for (int[] edge : edges) {
      final int index = edge[3];
      // Deleting the `edge` increases the MST's weight or makes the MST
      // invalid.
      if (getMSTWeight(n, edges, new int[] {}, index) > mstWeight)
        criticalEdges.add(index);
      // If an edge can be in any MST, we can always add `edge` to the edge set.
      else if (getMSTWeight(n, edges, edge, -1) == mstWeight)
        pseudoCriticalEdges.add(index);
    }

    return List.of(criticalEdges, pseudoCriticalEdges);
  }

  private int getMSTWeight(int n, int[][] edges, int[] firstEdge, int deletedEdgeIndex) {
    int mstWeight = 0;
    UnionFind uf = new UnionFind(n);

    if (firstEdge.length == 4) {
      uf.unionByRank(firstEdge[0], firstEdge[1]);
      mstWeight += firstEdge[2];
    }

    for (int[] edge : edges) {
      final int u = edge[0];
      final int v = edge[1];
      final int weight = edge[2];
      final int index = edge[3];
      if (index == deletedEdgeIndex)
        continue;
      if (uf.find(u) == uf.find(v))
        continue;
      uf.unionByRank(u, v);
      mstWeight += weight;
    }

    final int root = uf.find(0);
    for (int i = 0; i < n; ++i)
      if (uf.find(i) != root)
        return Integer.MAX_VALUE;

    return mstWeight;
  }
}
