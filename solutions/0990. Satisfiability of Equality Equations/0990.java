class UnionFind {
  public int[] id;

  public UnionFind(int n) {
    id = new int[n];
    for (int i = 0; i < n; ++i)
      id[i] = i;
  }

  public void union(int u, int v) {
    id[find(u)] = find(v);
  }

  public int find(int u) {
    return id[u] == u ? u : (id[u] = find(id[u]));
  }
}

class Solution {
  public boolean equationsPossible(String[] equations) {
    UnionFind uf = new UnionFind(26);

    for (final String e : equations)
      if (e.charAt(1) == '=') {
        final int x = e.charAt(0) - 'a';
        final int y = e.charAt(3) - 'a';
        uf.union(x, y);
      }

    for (final String e : equations)
      if (e.charAt(1) == '!') {
        final int x = e.charAt(0) - 'a';
        final int y = e.charAt(3) - 'a';
        if (uf.find(x) == uf.find(y))
          return false;
      }

    return true;
  }
}
