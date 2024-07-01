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
  public int earliestAcq(int[][] logs, int n) {
    UnionFind uf = new UnionFind(n);

    // Sort `logs` by timestamp.
    Arrays.sort(logs, (a, b) -> a[0] - b[0]);

    for (int[] log : logs) {
      final int timestamp = log[0];
      final int x = log[1];
      final int y = log[2];
      uf.unionByRank(x, y);
      if (uf.getCount() == 1)
        return timestamp;
    }

    return -1;
  }
}
