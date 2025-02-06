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
  public int minMalwareSpread(int[][] graph, int[] initial) {
    final int n = graph.length;
    UnionFind uf = new UnionFind(n);
    int[] ufSize = new int[n];
    int[] malwareCount = new int[n];

    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j)
        if (graph[i][j] == 1)
          uf.unionByRank(i, j);

    for (int i = 0; i < n; ++i)
      ++ufSize[uf.find(i)];

    for (final int i : initial)
      ++malwareCount[uf.find(i)];

    Arrays.sort(initial);

    int ans = initial[0];
    int maxUfSize = 0;

    // Find the maximum union's malware if it only contains 1 malware.
    for (final int i : initial) {
      final int id = uf.find(i);
      if (ufSize[id] > maxUfSize && malwareCount[id] == 1) {
        maxUfSize = ufSize[id];
        ans = i;
      }
    }

    return ans;
  }
}
