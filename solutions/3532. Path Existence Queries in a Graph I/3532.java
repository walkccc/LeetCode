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
  public boolean[] pathExistenceQueries(int n, int[] nums, int maxDiff, int[][] queries) {
    boolean[] ans = new boolean[queries.length];
    UnionFind uf = new UnionFind(n);

    for (int i = 1; i < n; ++i)
      if (Math.abs(nums[i] - nums[i - 1]) <= maxDiff)
        uf.unionByRank(i, i - 1);

    for (int i = 0; i < queries.length; ++i) {
      final int u = queries[i][0];
      final int v = queries[i][1];
      ans[i] = uf.find(u) == uf.find(v);
    }

    return ans;
  }
}
