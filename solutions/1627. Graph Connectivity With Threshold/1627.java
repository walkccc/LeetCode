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

  public int find(int u) {
    return id[u] == u ? u : (id[u] = find(id[u]));
  }

  private int[] id;
  private int[] rank;
}

class Solution {
  public List<Boolean> areConnected(int n, int threshold, int[][] queries) {
    List<Boolean> ans = new ArrayList<>();
    UnionFind uf = new UnionFind(n + 1);

    for (int z = threshold + 1; z <= n; ++z)
      for (int x = z * 2; x <= n; x += z)
        uf.unionByRank(z, x);

    for (int[] query : queries) {
      final int a = query[0];
      final int b = query[1];
      ans.add(uf.find(a) == uf.find(b));
    }

    return ans;
  }
}
