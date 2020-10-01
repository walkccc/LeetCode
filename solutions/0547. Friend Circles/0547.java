class Solution {
  public int findCircleNum(int[][] M) {
    final int n = M.length;

    UF uf = new UF(n);
    Set<Integer> friendCircle = new HashSet<>();

    for (int i = 0; i < n; ++i)
      for (int j = i; j < n; ++j)
        if (M[i][j] == 1)
          uf.union(i, j);

    for (int i = 0; i < n; ++i)
      friendCircle.add(uf.find(i));

    return friendCircle.size();
  }
}

class UF {
  public UF(int n) {
    rank = new int[n];
    parent = new int[n];

    for (int i = 0; i < parent.length; ++i)
      parent[i] = i;
  }

  public void union(int u, int v) {
    int pu = find(u);
    int pv = find(v);
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
    while (u != parent[u]) {
      parent[u] = parent[parent[u]];
      u = parent[u];
    }

    return u;
  }

  private int[] rank;
  private int[] parent;
}