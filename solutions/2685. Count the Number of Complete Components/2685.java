class UnionFind {
  public UnionFind(int n) {
    id = new int[n];
    rank = new int[n];
    nodeCount = new int[n];
    edgeCount = new int[n];
    for (int i = 0; i < n; ++i) {
      id[i] = i;
      nodeCount[i] = 1;
    }
  }

  public void unionByRank(int u, int v) {
    final int i = find(u);
    final int j = find(v);
    ++edgeCount[i];
    if (i == j)
      return;
    if (rank[i] < rank[j]) {
      id[i] = j;
      edgeCount[j] += edgeCount[i];
      nodeCount[j] += nodeCount[i];
    } else if (rank[i] > rank[j]) {
      id[j] = i;
      edgeCount[i] += edgeCount[j];
      nodeCount[i] += nodeCount[j];
    } else {
      id[i] = j;
      edgeCount[j] += edgeCount[i];
      nodeCount[j] += nodeCount[i];
      ++rank[j];
    }
  }

  public int find(int u) {
    return id[u] == u ? u : (id[u] = find(id[u]));
  }

  public boolean isComplete(int u) {
    return nodeCount[u] * (nodeCount[u] - 1) / 2 == edgeCount[u];
  }

  private int[] id;
  private int[] rank;
  private int[] nodeCount;
  private int[] edgeCount;
}

class Solution {
  public int countCompleteComponents(int n, int[][] edges) {
    int ans = 0;
    UnionFind uf = new UnionFind(n);
    Set<Integer> parents = new HashSet<>();

    for (int[] edge : edges) {
      final int u = edge[0];
      final int v = edge[1];
      uf.unionByRank(u, v);
    }

    for (int i = 0; i < n; ++i) {
      final int parent = uf.find(i);
      if (parents.add(parent) && uf.isComplete(parent))
        ++ans;
    }

    return ans;
  }
}
