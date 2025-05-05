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
  public int numberOfComponents(int[][] properties, int k) {
    final int n = properties.length;
    Set<Integer>[] propertySets = getPropertySets(properties);
    UnionFind uf = new UnionFind(n);

    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j) {
        Set<Integer> intersection = new HashSet<>(propertySets[i]);
        intersection.retainAll(propertySets[j]);
        if (intersection.size() >= k)
          uf.unionByRank(i, j);
      }

    return uf.getCount();
  }

  private Set<Integer>[] getPropertySets(int[][] properties) {
    Set<Integer>[] propertySets = new Set[properties.length];
    for (int i = 0; i < properties.length; ++i)
      propertySets[i] = Arrays.stream(properties[i]).boxed().collect(Collectors.toSet());
    return propertySets;
  }
}
