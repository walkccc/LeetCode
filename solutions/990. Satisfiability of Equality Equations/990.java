class UnionFind {
  public UnionFind(int n) {
    id = new int[n];
    rank = new int[n];
    for (int i = 0; i < n; ++i)
      id[i] = i;
  }

  public void unionByRank(int u, int v) {
    final int i = find(u);
    final int j = find(v);
    if (i == j)
      return;
    if (rank[i] < rank[j]) {
      id[i] = j;
    } else if (rank[i] > rank[j]) {
      id[j] = i;
    } else {
      id[i] = j;
      ++rank[j];
    }
  }

  public int find(int u) {
    return id[u] == u ? u : (id[u] = find(id[u]));
  }

  private int[] id;
  private int[] rank;
}

class Solution {
  public boolean equationsPossible(String[] equations) {
    UnionFind uf = new UnionFind(26);

    for (final String e : equations)
      if (e.charAt(1) == '=') {
        final int x = e.charAt(0) - 'a';
        final int y = e.charAt(3) - 'a';
        uf.unionByRank(x, y);
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
