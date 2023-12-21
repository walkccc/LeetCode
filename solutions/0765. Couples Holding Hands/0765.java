class UnionFind {
  public UnionFind(int n) {
    count = n;
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
    --count;
  }

  public int getCount() {
    return count;
  }

  private int count;
  private int[] id;
  private int[] rank;

  private int find(int u) {
    return id[u] == u ? u : (id[u] = find(id[u]));
  }
}

class Solution {
  public int minSwapsCouples(int[] row) {
    final int n = row.length / 2;
    UnionFind uf = new UnionFind(n);

    for (int i = 0; i < n; ++i) {
      final int a = row[2 * i];
      final int b = row[2 * i + 1];
      uf.unionByRank(a / 2, b / 2);
    }

    return n - uf.getCount();
  }
}
