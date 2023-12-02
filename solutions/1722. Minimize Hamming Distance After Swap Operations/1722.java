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
  public int minimumHammingDistance(int[] source, int[] target, int[][] allowedSwaps) {
    final int n = source.length;
    int ans = 0;
    UnionFind uf = new UnionFind(n);
    Map<Integer, Integer>[] groupIdToCount = new Map[n];

    for (int i = 0; i < n; ++i)
      groupIdToCount[i] = new HashMap<>();

    for (int[] allowedSwap : allowedSwaps) {
      final int a = allowedSwap[0];
      final int b = allowedSwap[1];
      uf.unionByRank(a, b);
    }

    for (int i = 0; i < n; ++i)
      groupIdToCount[uf.find(i)].merge(source[i], 1, Integer::sum);

    for (int i = 0; i < n; ++i) {
      final int groupId = uf.find(i);
      Map<Integer, Integer> count = groupIdToCount[groupId];
      if (!count.containsKey(target[i]))
        ++ans;
      else if (count.merge(target[i], -1, Integer::sum) == 0)
        count.remove(target[i]);
    }

    return ans;
  }
}
