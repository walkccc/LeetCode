class UnionFind {
  public UnionFind(int n) {
    count = n;
    id = new int[n];
    rank = new int[n];
    for (int i = 0; i < n; ++i)
      id[i] = i;
  }

  public void union(int u, int v) {
    int i = find(u);
    int j = find(v);
    if (i == j)
      return;
    if (rank[i] > rank[j]) {
      final int temp = i;
      i = j;
      j = temp;
    } else if (rank[i] == rank[j]) {
      ++rank[j];
    }
    id[i] = j;
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
      uf.union(x, y);
      if (uf.getCount() == 1)
        return timestamp;
    }

    return -1;
  }
}
