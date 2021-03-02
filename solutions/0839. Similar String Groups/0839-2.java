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
  public int numSimilarGroups(String[] A) {
    UF uf = new UF(A.length);

    for (int i = 1; i < A.length; ++i)
      for (int j = 0; j < i; ++j)
        if (isSimilar(A[i], A[j]))
          uf.union(i, j);

    return uf.getSize();
  }

  private boolean isSimilar(final String X, final String Y) {
    int diff = 0;
    for (int i = 0; i < X.length(); ++i)
      if (X.charAt(i) != Y.charAt(i) && ++diff > 2)
        return false;
    return true;
  }
}
