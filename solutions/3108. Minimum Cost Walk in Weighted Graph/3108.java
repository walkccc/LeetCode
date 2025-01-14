class UnionFind {
  public UnionFind(int n) {
    id = new int[n];
    rank = new int[n];
    weight = new int[n];
    for (int i = 0; i < n; ++i)
      id[i] = i;
    // 2^17 - 1 is the minimum number in the form 2^x - 1 > 10^5.
    Arrays.fill(weight, (1 << 17) - 1);
  }

  public void unionByRank(int u, int v, int w) {
    final int i = find(u);
    final int j = find(v);
    final int newWeight = weight[i] & weight[j] & w;
    weight[i] = newWeight;
    weight[j] = newWeight;
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

  public int getMinCost(int u, int v) {
    if (u == v)
      return 0;
    final int i = find(u);
    final int j = find(v);
    return i == j ? weight[i] : -1;
  }

  private int[] id;
  private int[] rank;
  private int[] weight;

  private int find(int u) {
    return id[u] == u ? u : (id[u] = find(id[u]));
  }
}

class Solution {
  public int[] minimumCost(int n, int[][] edges, int[][] query) {
    int[] ans = new int[query.length];
    UnionFind uf = new UnionFind(n);

    for (int[] edge : edges) {
      final int u = edge[0];
      final int v = edge[1];
      final int w = edge[2];
      uf.unionByRank(u, v, w);
    }

    for (int i = 0; i < query.length; ++i) {
      final int u = query[i][0];
      final int v = query[i][1];
      ans[i] = uf.getMinCost(u, v);
    }

    return ans;
  }
}
