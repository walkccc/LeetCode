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
  public boolean[] friendRequests(int n, int[][] restrictions, int[][] requests) {
    boolean[] ans = new boolean[requests.length];
    UnionFind uf = new UnionFind(n);

    for (int i = 0; i < requests.length; ++i) {
      final int pu = uf.find(requests[i][0]);
      final int pv = uf.find(requests[i][1]);
      boolean isValid = true;
      if (pu != pv)
        for (int[] restriction : restrictions) {
          final int px = uf.find(restriction[0]);
          final int py = uf.find(restriction[1]);
          if (pu == px && pv == py || pu == py && pv == px) {
            isValid = false;
            break;
          }
        }
      ans[i] = isValid;
      if (isValid)
        uf.unionByRank(pu, pv);
    }

    return ans;
  }
}
