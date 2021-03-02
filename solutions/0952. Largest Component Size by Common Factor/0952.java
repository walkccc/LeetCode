class Solution {
  public int largestComponentSize(int[] A) {
    final int n = Arrays.stream(A).max().getAsInt();

    int ans = 0;
    UF uf = new UF(n);
    Map<Integer, Integer> count = new HashMap<>();

    for (int a : A)
      for (int num = 2; num <= (int) Math.sqrt(a); ++num)
        if (a % num == 0) {
          uf.union(a, num);
          uf.union(a, a / num);
        }

    for (int a : A) {
      int pa = uf.find(a);
      count.put(pa, count.getOrDefault(pa, 0) + 1);
      ans = Math.max(ans, count.get(pa));
    }

    return ans;
  }
}

class UF {
  public UF(int n) {
    rank = new int[n + 1];
    parent = new int[n + 1];

    for (int i = 0; i < parent.length; ++i)
      parent[i] = i;
  }

  public void union(int u, int v) {
    int pu = find(u);
    int pv = find(v);
    if (pu == pv)
      return;

    if (rank[pu] < rank[pv])
      parent[pu] = pv;
    else if (rank[pv] < rank[pu])
      parent[pv] = pu;
    else {
      parent[pu] = pv;
      ++rank[pv];
    }
  }

  public int find(int u) {
    while (u != parent[u]) {
      parent[u] = parent[parent[u]];
      u = parent[u];
    }

    return u;
  }

  private int[] rank;
  private int[] parent;
}
