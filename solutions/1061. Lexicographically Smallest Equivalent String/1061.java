class UF {
  public UF(int n) {
    parent = new int[n];

    for (int i = 0; i < n; ++i)
      parent[i] = i;
  }

  // pu > pv, so we assign the smaller to the bigger's parent
  public void union(int pu, int pv) {
    parent[pu] = pv;
  }

  public int find(int u) {
    if (u != parent[u])
      parent[u] = find(parent[u]);
    return parent[u];
  }

  private int[] parent;
}

class Solution {
  public String smallestEquivalentString(String A, String B, String S) {
    StringBuilder sb = new StringBuilder();
    UF uf = new UF(26);

    for (int i = 0; i < A.length(); ++i) {
      final int a = A.charAt(i) - 'a';
      final int b = B.charAt(i) - 'a';
      final int pa = uf.find(a);
      final int pb = uf.find(b);
      if (pa > pb)
        uf.union(pa, pb);
      else
        uf.union(pb, pa);
    }

    for (final char c : S.toCharArray())
      sb.append((char) ('a' + uf.find(c - 'a')));

    return sb.toString();
  }
}
