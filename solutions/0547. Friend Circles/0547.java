class UF {
  public UF(int n) {
    count = n;
    id = new int[n];
    for (int i = 0; i < n; ++i)
      id[i] = i;
  }

  public void union(int u, int v) {
    final int i = find(u);
    final int j = find(v);
    if (i == j)
      return;
    id[i] = j;
    --count;
  }

  public int getCount() {
    return count;
  }

  private int count;
  private int[] id;

  private int find(int u) {
    return id[u] == u ? u : (id[u] = find(id[u]));
  }
}

class Solution {
  public int findCircleNum(int[][] M) {
    final int n = M.length;
    UF uf = new UF(n);

    for (int i = 0; i < n; ++i)
      for (int j = i; j < n; ++j)
        if (M[i][j] == 1)
          uf.union(i, j);

    return uf.getCount();
  }
}
