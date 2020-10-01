class Solution {
  public boolean validTree(int n, int[][] edges) {
    if (n == 0 || edges.length != n - 1)
      return false;

    UF uf = new UF(n);
    Set<Integer> parents = new HashSet<>();

    for (final int[] edge : edges)
      uf.union(edge[0], edge[1]);

    for (int i = 0; i < n; ++i)
      parents.add(uf.find(i));

    return parents.size() == 1;
  }
}

class UF {
  public UF(int n) {
    rank = new int[n];
    parent = new int[n];

    for (int i = 0; i < n; ++i)
      parent[i] = i;
  }

  public void union(int u, int v) {
    final int pu = find(u);
    final int pv = find(v);
    if (pu == pv)
      return;

    if (rank[pu] < rank[pv])
      parent[pu] = pv;
    else if (rank[pv] < rank[pu])
      parent[pv] = pu;
    else {
      parent[pu] = pv;
      ++rank[pv];
    }
  }

  public int find(int u) {
    if (u != parent[u])
      parent[u] = find(parent[u]);
    return parent[u];
  }

  private int[] rank;
  private int[] parent;
}