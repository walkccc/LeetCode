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
  public int numberOfGoodPaths(int[] vals, int[][] edges) {
    final int n = vals.length;
    int ans = n;
    UnionFind uf = new UnionFind(n);
    List<Integer>[] tree = new List[n];
    Map<Integer, List<Integer>> valToNodes = new TreeMap<>();

    for (int i = 0; i < n; ++i)
      tree[i] = new ArrayList<>();

    for (int[] edge : edges) {
      final int u = edge[0];
      final int v = edge[1];
      if (vals[v] <= vals[u])
        tree[u].add(v);
      if (vals[u] <= vals[v])
        tree[v].add(u);
    }

    for (int i = 0; i < vals.length; ++i) {
      valToNodes.putIfAbsent(vals[i], new ArrayList<>());
      valToNodes.get(vals[i]).add(i);
    }

    for (Map.Entry<Integer, List<Integer>> entry : valToNodes.entrySet()) {
      final int val = entry.getKey();
      List<Integer> nodes = entry.getValue();
      for (final int u : nodes)
        for (final int v : tree[u])
          uf.unionByRank(u, v);
      Map<Integer, Integer> rootCount = new HashMap<>();
      for (final int u : nodes)
        rootCount.merge(uf.find(u), 1, Integer::sum);
      // For each group, C(count, 2) := count * (count - 1) / 2
      for (final int count : rootCount.values())
        ans += count * (count - 1) / 2;
    }

    return ans;
  }
}
