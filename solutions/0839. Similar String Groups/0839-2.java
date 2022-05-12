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
  public int numSimilarGroups(String[] A) {
    UF uf = new UF(A.length);

    for (int i = 1; i < A.length; ++i)
      for (int j = 0; j < i; ++j)
        if (isSimilar(A[i], A[j]))
          uf.union(i, j);

    return uf.getCount();
  }

  private boolean isSimilar(final String X, final String Y) {
    int diff = 0;
    for (int i = 0; i < X.length(); ++i)
      if (X.charAt(i) != Y.charAt(i) && ++diff > 2)
        return false;
    return true;
  }
}
