class UF {
  public UF(int n) {
    id = new int[n];
    for (int i = 0; i < n; ++i)
      id[i] = i;
  }

  public void union(int u, int v) {
    final int i = find(u);
    final int j = find(v);
    if (i > j)
      id[i] = j;
    else
      id[j] = i;
  }

  public int find(int u) {
    return id[u] == u ? u : (id[u] = find(id[u]));
  }

  private int[] id;
}

class Solution {
  public String smallestEquivalentString(String A, String B, String S) {
    StringBuilder sb = new StringBuilder();
    UF uf = new UF(26);

    for (int i = 0; i < A.length(); ++i)
      uf.union(A.charAt(i) - 'a', B.charAt(i) - 'a');

    for (final char c : S.toCharArray())
      sb.append((char) ('a' + uf.find(c - 'a')));

    return sb.toString();
  }
}
