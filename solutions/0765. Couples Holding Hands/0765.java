class UF {
  public UF(int n) {
    size = n;
    parent = new int[n];

    for (int i = 0; i < n; ++i)
      parent[i] = i;
  }

  public void union(int u, int v) {
    final int pu = find(u);
    final int pv = find(v);
    if (pu == pv)
      return;

    parent[pu] = pv;
    --size;
  }

  public int getSize() {
    return size;
  }

  private int size;
  private int[] parent;

  private int find(int u) {
    if (u != parent[u])
      parent[u] = find(parent[u]);
    return parent[u];
  }
}

class Solution {
  public int minSwapsCouples(int[] row) {
    final int n = row.length / 2;
    UF uf = new UF(n);

    for (int i = 0; i < n; ++i) {
      final int a = row[2 * i];
      final int b = row[2 * i + 1];
      uf.union(a / 2, b / 2);
    }

    return n - uf.getSize();
  }
}
