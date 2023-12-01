class UnionFind {
  public UnionFind(int n) {
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
  public String smallestEquivalentString(String s1, String s2, String baseStr) {
    StringBuilder sb = new StringBuilder();
    UnionFind uf = new UnionFind(26);

    for (int i = 0; i < s1.length(); ++i)
      uf.union(s1.charAt(i) - 'a', s2.charAt(i) - 'a');

    for (final char c : baseStr.toCharArray())
      sb.append((char) ('a' + uf.find(c - 'a')));

    return sb.toString();
  }
}
