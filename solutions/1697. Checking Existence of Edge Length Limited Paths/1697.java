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
  public boolean[] distanceLimitedPathsExist(int n, int[][] edgeList, int[][] queries) {
    boolean[] ans = new boolean[queries.length];
    int[][] qs = new int[queries.length][4];
    UnionFind uf = new UnionFind(n);

    for (int i = 0; i < queries.length; ++i) {
      qs[i][0] = queries[i][0];
      qs[i][1] = queries[i][1];
      qs[i][2] = queries[i][2];
      qs[i][3] = i;
    }

    Arrays.sort(qs, (a, b) -> Integer.compare(a[2], b[2]));
    Arrays.sort(edgeList, (a, b) -> Integer.compare(a[2], b[2]));

    int i = 0; // i := edgeList's index
    for (int[] q : qs) {
      // Union edges whose distances < limit (q[2]).
      while (i < edgeList.length && edgeList[i][2] < q[2])
        uf.unionByRank(edgeList[i][0], edgeList[i++][1]);
      if (uf.find(q[0]) == uf.find(q[1]))
        ans[q[3]] = true;
    }

    return ans;
  }
}
